class Solution {
public:
    long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

        int n = nums1.size();
        std::vector<std::pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums1[i], nums2[i]});
        }
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> topKHeap;
        long topKSum = 0;
        for (int i = 0; i < k; ++i) {
            topKSum += pairs[i].first;
            topKHeap.push(pairs[i].first);
        }


        long answer = topKSum * pairs[k - 1].second;


        for (int i = k; i < n; ++i) {
            topKSum += pairs[i].first - topKHeap.top();
            topKHeap.pop();
            topKHeap.push(pairs[i].first);
            answer = std::max(answer, topKSum * pairs[i].second);
        }

        return answer;
    }
};