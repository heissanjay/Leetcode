class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        dp = {}
        cuts = [0] + sorted(cuts) + [n]

        def cost(l,r):
            if(l,r) in dp:
                return dp[(l,r)]

            if r -l == 1:
                return 0

            ans = min(cost(l,m) + cost(m,r) + cuts[r] - cuts[l] for m in range(l+1,r))
            dp[(l,r)] = ans
            return ans
        return cost(0,len(cuts)-1)