class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& accessTimes) {
        unordered_map<string, vector<int>> map;


        for (const vector<string>& access : accessTimes) {
            string employee = access[0];
            int timestamp = stoi(access[1]);
            map[employee].push_back(timestamp);
        }

        vector<string> result;

        
        for (auto& [employee, times] : map) {
            sort(times.begin(), times.end());

            
            for (int i = 0; i < times.size(); ++i) {
                int j = i;
                while (j < times.size() && times[j] - times[i] < 100) {
                    j++;
                }
                if (j - i >= 3) {
                    result.push_back(employee);
                    break;
                }
            }
        }

        return result;
    }
};
