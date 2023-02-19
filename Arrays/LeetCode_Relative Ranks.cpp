class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < score.size(); i++) {
            pairs.push_back({score[i], i});
        }
        sort(pairs.rbegin(), pairs.rend());
        
        vector<string> result(score.size());
        for (int i = 0; i < pairs.size(); i++) {
            int rank = i + 1;
            if (rank == 1) {
                result[pairs[i].second] = "Gold Medal";
            } else if (rank == 2) {
                result[pairs[i].second] = "Silver Medal";
            } else if (rank == 3) {
                result[pairs[i].second] = "Bronze Medal";
            } else {
                result[pairs[i].second] = to_string(rank);
            }
        }
        
        return result;
    }
};
