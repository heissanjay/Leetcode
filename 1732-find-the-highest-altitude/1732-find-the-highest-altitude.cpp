class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int maxElement  {0};
        int altitude {0};
        
        for (int gain: gains){
            altitude += gain;
            maxElement = max(maxElement,altitude);
        }
        
        return maxElement;
    }
};