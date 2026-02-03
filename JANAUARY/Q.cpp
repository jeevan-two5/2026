#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* ---------------- Problem 7 ---------------- */
/* Vaccination Strategy (SIR Model) */

void problem7()
{
    cout << "\n--- Problem 7: Vaccination Strategy ---\n";

    double S = 990, I = 10, R = 0; // Initial values
    double beta = 0.3, gamma = 0.1;
    double v; // vaccination rate
    double dt = 0.1;
    int steps = 1000;

    for (v = 0.0; v <= 1.0; v += 0.01)
    {
        S = 990;
        I = 10;
        R = 0;

        double maxI = I;

        for (int i = 0; i < steps; i++)
        {
            double dS = -beta * S * I / 1000 - v * S;
            double dI = beta * S * I / 1000 - gamma * I;
            double dR = gamma * I + v * S;

            S += dS * dt;
            I += dI * dt;
            R += dR * dt;

            if (I > maxI)
                maxI = I;
        }

        if (maxI <= 100) // 10% of population
        {
            cout << "Minimum vaccination rate v = " << v << endl;
            break;
        }
    }
}

/* ---------------- Problem 8 ---------------- */
/* Holling Type II (RK4 Method) */

double prey(double x, double y)
{
    double r = 0.5, K = 100, a = 0.02;
    return r * x * (1 - x / K) - (a * x * y) / (1 + x);
}

double predator(double x, double y)
{
    double b = 0.01, d = 0.1;
    return (b * x * y) / (1 + x) - d * y;
}

void problem8()
{
    cout << "\n--- Problem 8: Non-linear Predation (RK4) ---\n";

    double x = 40, y = 9; // prey, predator
    double dt = 0.1;
    int n = 200;

    for (int i = 0; i < n; i++)
    {
        double k1x = dt * prey(x, y);
        double k1y = dt * predator(x, y);

        double k2x = dt * prey(x + k1x / 2, y + k1y / 2);
        double k2y = dt * predator(x + k1x / 2, y + k1y / 2);

        double k3x = dt * prey(x + k2x / 2, y + k2y / 2);
        double k3y = dt * predator(x + k2x / 2, y + k2y / 2);

        double k4x = dt * prey(x + k3x, y + k3y);
        double k4y = dt * predator(x + k3x, y + k3y);

        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
    }

    cout << "Final Prey: " << x << endl;
    cout << "Final Predator: " << y << endl;
}

/* ---------------- Problem 9 ---------------- */
/* R0 Heatmap */

void problem9()
{
    cout << "\n--- Problem 9: R0 Heatmap ---\n";

    double beta, gamma;

    cout << fixed << setprecision(2);

    for (beta = 0.1; beta <= 1.0; beta += 0.1)
    {
        for (gamma = 0.1; gamma <= 1.0; gamma += 0.1)
        {
            double R0 = beta / gamma;
            cout << setw(6) << R0 << " ";
        }
        cout << endl;
    }
}

/* ---------------- Problem 10 ---------------- */
/* Numerical Jacobian */

double f(double x, double y)
{
    return x * (1 - y);
}

double g(double x, double y)
{
    return y * (x - 1);
}

void problem10()
{
    cout << "\n--- Problem 10: Numerical Jacobian ---\n";

    double x = 1.0, y = 1.0; // equilibrium
    double h = 0.001;

    double dfdx = (f(x + h, y) - f(x - h, y)) / (2 * h);
    double dfdy = (f(x, y + h) - f(x, y - h)) / (2 * h);

    double dgdx = (g(x + h, y) - g(x - h, y)) / (2 * h);
    double dgdy = (g(x, y + h) - g(x, y - h)) / (2 * h);

    cout << "Jacobian Matrix:\n";
    cout << dfdx << "  " << dfdy << endl;
    cout << dgdx << "  " << dgdy << endl;
}

/* ---------------- Main ---------------- */

int main()
{
    problem7();
    problem8();
    problem9();
    problem10();

    return 0;
}
