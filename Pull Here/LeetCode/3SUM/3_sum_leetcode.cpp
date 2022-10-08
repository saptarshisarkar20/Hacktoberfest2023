class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int twosum = 0;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            int target = 0 - nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                twosum = nums[left] + nums[right];

                if (twosum < target)
                {
                    left++;
                }
                else if (twosum > target)
                {
                    right--;
                }
                else
                {
                    vector<int> triple(3, 0);
                    triple[0] = nums[i];
                    triple[1] = nums[left];
                    triple[2] = nums[right];
                    res.push_back(triple);

                    while (left < right && nums[left] == triple[1])
                        left++;

                    while (left < right && nums[right] == triple[2])
                        right--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};