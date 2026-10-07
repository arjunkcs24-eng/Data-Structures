class Solution:
    def getConcatenation(self, nums: list[int]) -> list[int]:
        ans=[]
        for i in range(2*len(nums)):
            ans.append(nums[i%len(nums)])
        return ans