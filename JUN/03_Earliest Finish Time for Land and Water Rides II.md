<img width="1242" height="531" alt="image" src="https://github.com/user-attachments/assets/f54f9caf-20b8-4f30-80f7-b7365ac8ff9f" />
<img width="659" height="715" alt="image" src="https://github.com/user-attachments/assets/5587035e-17e1-4f09-b082-879bdeaa4004" />

###### INTUITION

<img width="722" height="625" alt="image" src="https://github.com/user-attachments/assets/450c7c0f-2266-457d-a919-8c70bc42178a" />
<img width="721" height="351" alt="image" src="https://github.com/user-attachments/assets/fe629b81-59c7-40f6-88df-2e6e7216f4be" />


###### C O D E
```cpp
  class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // --- SCENARIO 1: Land Ride First -> Water Ride Second ---
        int minEndLand = INT_MAX;
        for (int i = 0; i < n; i++) {
            minEndLand = min(minEndLand, landStartTime[i] + landDuration[i]);
        }

        int case1Best = INT_MAX;
        for (int j = 0; j < m; j++) {
            int actualStart = max(minEndLand, waterStartTime[j]);
            int finishTime = actualStart + waterDuration[j];
            case1Best = min(case1Best, finishTime);
        }

        // --- SCENARIO 2: Water Ride First -> Land Ride Second ---
        int minEndWater = INT_MAX;
        for (int j = 0; j < m; j++) {
            minEndWater = min(minEndWater, waterStartTime[j] + waterDuration[j]);
        }

        int case2Best = INT_MAX;
        for (int i = 0; i < n; i++) {
            int actualStart = max(minEndWater, landStartTime[i]);
            int finishTime = actualStart + landDuration[i];
            case2Best = min(case2Best, finishTime);
        }

        // Return the best outcome from both sequences
        return min(case1Best, case2Best);
    }
};
```

