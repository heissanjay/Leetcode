class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        
        int i = 0;
        while ( i < n-2) {
            if ((arr[i] - arr[i+1]) == (arr[i+1] - arr[i+2])) {
                i++;
            } else {
                return false;
            }
        }
        return true;
    }
};