#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right)  {};
};


class Solution {
public:
    int minOperations(string s){

        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] == '0')
                cnt++;
        }
        for (int i = 1; i < n; i += 2) {
            if (s[i] == '1')
                cnt++;
        }

        return min(cnt, n - cnt);

    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();

        string worrd1 = "";
        string worrd2 = "";

        for (int i = 0; i < n; ++i) {
            worrd1.append(word1[i]);
        }

        for (int i = 0; i < m; ++i) {
            worrd2.append(word2[i]);
        }

        return worrd1 == worrd2 ? true: false;
    }
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int leftover = money - (prices[0] + prices[1]);
        if (leftover < 0) {
            return money;
        }
        return leftover;

    }
    TreeNode* vectorToTree(vector<string>& nodes) {
        if (nodes.empty() || nodes[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
    void dfs(TreeNode* root, unordered_map<int,int>& mapp, int& pathCnt) {
        if (root == nullptr) return;

        mapp[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            if (this->hasPseudoPalindromicPath(mapp))
                pathCnt++;
        }

        dfs(root->left, mapp,pathCnt);
        dfs(root->right, mapp, pathCnt);

        mapp[root->val]--;

    }
    bool hasPseudoPalindromicPath(unordered_map<int,int>& count){
        int odd = 0;
        for(auto& entry: count) {
            if (entry.second % 2 != 0) {
                odd++;
                if (odd > 1) return false;
            }
        }
        return true;
    }
    int pseudoPalindromicPath(TreeNode* root) {
        unordered_map<int,int> count;
        int pathCnt = 0;
        dfs(root,count,pathCnt);
        return pathCnt;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            int sqr = nums[i] * nums[i];
            result.push_back(sqr);
        }
        sort(result.begin(), result.end());

        return result;
    }
    string mergeAlternately(string& word1, string& word2) {
        int n = word1.length();
        int m = word2.length();
        string result = "";
        int i=0, j=0;
        while (i < n && j < m) {
            result += word1[i];
            result += word2[j];
            i++;
            j++;
        }

        while (i < n) {
            result += word1[i];
            i++;
        }

        while (j < m) {
            result += word2[j];
            j++;
        }
        return result;
    }
    string gcdOfStrings(string str1, string str2) {
        if (! ((str1+str2) == (str2+str1)))
            return "";

        int n = str1.length();
        int m = str2.length();

        int gcd;
        if (n > m) {
            gcd = findGCD(n,m);
        } else {
            gcd = findGCD(m, n);
        }
        return str1.substr(0, gcd);
    }
    int findGCD (int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result;
        int max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (max < candies[i])
                max = candies[i];
        }

        for (int i = 0; i < n; ++i) {

            if (max <= candies[i]+extraCandies)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();

        for (int i = 0; i < n; ++i)
        {
            if (flowerbed[i] == 0 &&
                (flowerbed[i - 1] == 0) &&
                (flowerbed[i + 1] == 0)
                    )
            {
                flowerbed[i] = 1;
                k--;
            }
        }
        return k <= 0;
    }
    string reverseVowels(string s) {
//        string to return
string result;
//        collect all the vowels in the string inside a list
vector<char> vowels;
        // iter over the s to push all the vowels (both UPper and lower case)
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.push_back(s[i]);
            }
        }

        // place a point in the last pos of the vowels list
        int v = vowels.size() - 1;

//        iter over the string again

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
                ) {
                result.push_back(vowels.at(v));
                v--;
            } else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
    string reverseWords(string s) {
        stack<string> stk;
        string word = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                word += s[i];

            } else {
                if(!word.empty())
                    stk.push(word);
                word = "";
            }
        }
        if (!word.empty())
            stk.push(word);

        string result;
        while (!stk.empty())
        {
            result.append(stk.top());
            stk.pop();
            if (!stk.empty()) {
                result += " ";
            }
        }
        return result;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n) + O(n) + O (n) = O (n)
            int n = nums.size();
            vector<int> res(n, 1);

            int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            res[i] *= leftProduct;
            leftProduct *= nums[i];
        }
        int rightProduct = 1;
        for (int i = n -1; i >= 0 ; --i) {
            res[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return res;


    }
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first_min = INT_MAX;
        int second_min = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (first_min >=  nums[i]) {
                first_min = nums[i];
            } else if (second_min >= nums[i]) {
                second_min = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
    void moveZeroes(vector<int>& nums) {
//        two pointers
        int i = 0;

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }

        }

    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;

        int i = 0;
        int j = tokens.size() - 1;

        while (i <= j) {
            if (power >= tokens[i]) {
                ++score;
                power -= tokens[i];
                i++;
            } else if (i < j && score > 0) {

                power += tokens[j];
                --j;
            } else {
                return score;
            }
        }

        return score;

    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m < n) return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == n;
    }
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maximumArea = INT_MIN;
        while (i <= j) {
//           calculate the width
            int width = j - i;

            // decide the height the frame
            int minHeight = min(heights[i], heights[j]);
            // calculate area
            int area = minHeight * width;

            maximumArea = max(area, maximumArea);

//            move the pointer to the smallest tower towards the center
            if (heights[i] <= heights[j])
                i++;
            else
                j--;
        }
        return maximumArea;
    }
    int minimumLength(string s){
        int left = 0;
        int right = s.length() - 1;

        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) left++;
            while (left <=right && s[right] == c ) right--;
        }

        return left > right ? 0 : (right - left) + 1;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        maxAvg = max(maxAvg, (double)sum / k);

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, (double) sum /k);
        }

        return maxAvg;
    }
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int ans;
        int n = s.length();
        int count = 0;

//        i -> k
for (int i = 0; i < k; i++) {
    count += vowels.count(s[i]);
}
ans = count;

for (int i = k; i < n; i++) { // k -> n
    count += vowels.count(s[i]) - vowels.count(s[i-k]);
    ans = max(ans, count);
}
return ans;

    }
    int longestOnes(vector<int>& nums) {
        int n = nums.size();
        int  start = 0;
        int end = 0;
        int res = 0;
        int cnt = 0;
        while (end < n) {
            if (nums[end] == 1)
                cnt++;
            // end - start + 1 = window size
            // cnt -> 1's count
            // window size - 1's count = zero's count

            while( end - start + 1 - cnt > 1 ) // we have more than K 0's in our window
            {
                if (nums[start] == 1)
                    cnt--;    // slide the window

                start++;
            }
            res = max(res, end-start +1);
            end++;

        }
        return res;
    }
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int res = 0;

        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 0);

            while (cnt > 1) {
                cnt -= (nums[start] == 0);
                start++;
            }

            res = max(res, i - start);

        }

        return res;

    }
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size();
        int res = 0;
        while (i < j ) {
            if (nums[i] + nums[j] == k) {
                res++;
                ++i;
                --j;
            }
            else if(nums[i] + nums[j] > k) {
                --j;
            } else {
                ++i;
            }
        }

        return res;
    }
    int compress(vector<char>& chars) {
        int k = 0;
        int n = chars.size();
        for (int i = 0, j = i + 1; i < n;) {
            while (j < n && chars[i] == chars[j] ) {
                j++;
            }

            chars[k++] = chars[i];

            int run_len = j - i;

            if (run_len > 1) {
                for (char charCount: to_string(run_len)) {
                    chars[k++] = charCount;
                }
            }

            i = j;
        }
        return k;
    }
    int pivotIndex(vector<int>& nums) {
        int start = 0;
        int last = accumulate(nums.begin(), nums.end(),0);

        for(int i =0; i < nums.size(); ++i) {
            last -= nums[i];

            if (start == last) {
                return i;
            }

            start += nums[i];
        }
        return -1;
    }
    int maxFrequencyElements(vector<int>& nums) {
            unordered_map<int,int> mapp;
            int maxFreq = 0;
            for (auto const& num: nums) {
                mapp[num]++;
                maxFreq = max(maxFreq, mapp[num]);
            }

            int cnt {0};

            for (auto const& it: mapp)
                if (it.second == maxFreq)
                    cnt += it.second;

            return cnt;

    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {1,2,2,3,1,4};
    cout << sol->maxFrequencyElements(nums);
    return 0;
}
