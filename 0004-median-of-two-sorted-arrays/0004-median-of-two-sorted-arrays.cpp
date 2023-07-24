class Solution {
private:
    vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> result_set;
        
        int n = nums1.size();
        int m = nums2.size();
        int i =0 , j = 0;
        while ( i < n && j < m ) {
            if (nums1[i] < nums2[j]) {
                result_set.push_back(nums1[i]);
                i++;
            } else {
                result_set.push_back(nums2[j]);
                j++;
            }
        }
        
        while ( i < n){
            result_set.push_back(nums1[i]);
            i++;
        }
        
        while(j < m){
            result_set.push_back(nums2[j]);
            j++;
        }
        
        return result_set;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.00000;
        vector<int> mergedArr = mergeSortedArrays(nums1,nums2);
        
        int len = mergedArr.size();

        return ( len % 2 != 0) ? mergedArr[len / 2]: (mergedArr[len/2] + mergedArr[len/2 - 1]) / 2.00000 ;
    }
};

















