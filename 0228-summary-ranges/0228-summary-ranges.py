from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums: 
            return []
        
        ranges = []
        start = nums[0]
        end = nums[0]
        
        for i in range(1, len(nums)):
            if nums[i] == end + 1:
                end = nums[i]
            else:
                ranges.append(self.getRangeString(start, end))
                start = nums[i]
                end = nums[i]
        
        ranges.append(self.getRangeString(start, end))
        return ranges
    
    def getRangeString(self, start: int, end: int) -> str:
        if start == end:
            return str(start)
        else:
            return str(start) + "->" + str(end)
