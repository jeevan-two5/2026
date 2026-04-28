"""Build directed and undirected graph views."""
from __future__ import annotations

from dataclasses import dataclass

import pandas as pd

from .config import EDGES_PARQUET


@dataclass
class GraphBundle:
    """Container for directed and undirected graph-tool graphs."""

    g_dir: object
    g_und: object
    node_to_idx: dict[int, int]
    idx_to_node: dict[int, int]


def _import_graph_tool():
    try:
        import graph_tool as gt  # type: ignore
        from graph_tool.all import Graph  # type: ignore
    except Exception as e:  # pragma: no cover
        raise RuntimeError(
            "graph-tool is required. Install with conda-forge environment.yml"
        ) from e
    return gt, Graph


def _make_node_mapping(edges: pd.DataFrame) -> tuple[dict[int, int], dict[int, int]]:
    nodes = pd.Index(pd.concat([edges["u"], edges["v"]], ignore_index=True).unique())
    node_to_idx = {int(n): i for i, n in enumerate(nodes.tolist())}
    idx_to_node = {i: int(n) for n, i in node_to_idx.items()}
    return node_to_idx, idx_to_node


def build_graphs(edges_parquet=EDGES_PARQUET) -> GraphBundle:
    """Build directed graph `G_dir` and undirected OR-edge graph `G_und`."""
    _, Graph = _import_graph_tool()
    edges = pd.read_parquet(edges_parquet)
    node_to_idx, idx_to_node = _make_node_mapping(edges)

    g_dir = Graph(directed=True)
    g_dir.add_vertex(len(node_to_idx))
    directed_edges = [(node_to_idx[int(u)], node_to_idx[int(v)]) for u, v in edges[["u", "v"]].itertuples(index=False)]
    g_dir.add_edge_list(directed_edges)
    try:
        g_dir.set_fast_edge_removal(True)
    except Exception:
        pass

    # OR-semantics undirected: edge exists if u->v OR v->u
    g_und = Graph(directed=False)
    g_und.add_vertex(len(node_to_idx))
    und_pairs = {
        (min(node_to_idx[int(u)], node_to_idx[int(v)]), max(node_to_idx[int(u)], node_to_idx[int(v)]))
        for u, v in edges[["u", "v"]].itertuples(index=False)
        if int(u) != int(v)
    }
    g_und.add_edge_list(list(und_pairs))

    return GraphBundle(g_dir=g_dir, g_und=g_und, node_to_idx=node_to_idx, idx_to_node=idx_to_node)

