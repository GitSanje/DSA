
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        values = set()
        for n in nums:
            if n in values:
                return True
            values.add(n)
        return False

    def containsDuplicate2(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums = sorted(nums) #O(nlog(n)
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False

obj = Solution()
nums1= [1,2,3,3]
nums2 = [1,1,1,3,3,4,3,2,4,2]
print(obj.containsDuplicate2(nums1))
print(obj.containsDuplicate(nums2))

