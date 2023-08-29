class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n, "");

        
        priority_queue<pair<int, int>> scoreIndexPairHeap;

        for (int i = 0; i < n; i++) {
            scoreIndexPairHeap.push({score[i], i});
        }

        int rank = 1;

        while (!scoreIndexPairHeap.empty()) {
            pair<int, int> athlete = scoreIndexPairHeap.top();
            scoreIndexPairHeap.pop();

            int index = athlete.second;

            if (rank == 1) {
                result[index] = "Gold Medal";
            } else if (rank == 2) {
                result[index] = "Silver Medal";
            } else if (rank == 3) {
                result[index] = "Bronze Medal";
            } else {
                result[index] = to_string(rank);
            }

            rank++;
        }

        return result;
    }
};
