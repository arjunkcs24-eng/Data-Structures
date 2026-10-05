class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        Map=dict()
        for i,n in enumerate(nums):
            diff=target-n
            if diff in Map:
                return [Map[diff],i]
            Map[n]=i