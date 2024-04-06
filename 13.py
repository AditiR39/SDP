class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[n], nums[i] = nums[i], nums[n]
                n += 1