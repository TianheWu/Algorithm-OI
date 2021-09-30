class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> sta_sity;
        string dest_city;
        for (int i = 0; i < paths.size(); i++) sta_sity[paths[i][0]]++;
        for (int i = 0; i < paths.size(); i++)
            if (!sta_sity.count(paths[i][1])) {
                dest_city = paths[i][1]; break;
            }
        return dest_city;
    }
};