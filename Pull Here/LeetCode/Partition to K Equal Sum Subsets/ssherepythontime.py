

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total_sum = sum(nums)
        if total_sum % k != 0:
            return False
        total_group = 0
        result = False
        
        def dfs(current, total_group, sum):
            nonlocal result
            if result:
                return
            if(total_group == k - 1):
                # print(' sum {} : current {}, total_group: {}, nums: {} : result: {} '.format(sum, current,total_group, nums, result))                 
                result = True
                return
            if(sum > total_sum//k):
                return
            if(sum == total_sum//k):
                # print(' sum {} : current {}, total_group: {}, nums: {} '.format(sum, current,total_group, nums))
                dfs(0, total_group + 1, 0)
            
            for i in range(current, len(nums)):
                if(sum + nums[i] > total_sum//k):
                    continue
                num = nums[i]
                nums.pop(i)
                dfs(i, total_group, sum + num)
                nums.insert(i, num)
        dfs(0, total_group, 0)
        return result


class Solution2:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total_sum = sum(nums)
        if total_sum % k != 0:
            return False
        total_group = 0
        result = False
        
        def dfs(current, total_group, sum):
            nonlocal result
            if result:
                return
            if(total_group == k - 1):
                # print(' sum {} : current {}, total_group: {}, nums: {} : result: {} '.format(sum, current,total_group, nums, result))                 
                result = True
                return
            if(sum > total_sum//k):
                return
            if(sum == total_sum//k):
                # print(' sum {} : current {}, total_group: {}, nums: {} '.format(sum, current,total_group, nums))
                dfs(0, total_group + 1, 0)
            
            for i in range(current, len(nums)):
                if(sum + nums[i] > total_sum//k):
                    continue
                num = nums[i]
                nums.pop(i)
                dfs(i, total_group, sum + num)
                nums.insert(i, num)
        dfs(0, total_group, 0)
        return result
