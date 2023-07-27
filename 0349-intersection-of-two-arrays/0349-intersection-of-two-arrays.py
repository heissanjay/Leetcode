class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        output =  []
        for _ in nums1:
            if _ in nums2:
                output.append(_)  
        return [*set(output)]
    
#         U+1F602