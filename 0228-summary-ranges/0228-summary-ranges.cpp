class Solution {
private:
    string getRangeString(int s, int e){
        if (s == e) return to_string(s);
        else return to_string(s) + "->"+ to_string(e);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<string> ranges;
        int start = nums[0];
        int end = nums[0];
            
        for (int i = 1; i < nums.size(); i++ ) {
            if (nums[i] == end + 1 ){
                end  = nums[i];
            }
            else {
                ranges.push_back(getRangeString(start,end));
                start = nums[i];
                end =nums[i];
            }
        }
        ranges.push_back(getRangeString(start,end));
        return ranges;
        
    }
};