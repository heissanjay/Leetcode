class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>  my_set;
        
        for (int i =0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]){
                    my_set.insert(nums1[i]);
                }
            }
        }
        
        vector<int> result;
        for(auto x: my_set){
            result.push_back(x);
        }
        return result;
    }
};