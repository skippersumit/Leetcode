class Solution
{
    public:
        int wiggleMaxLength(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 1)
            {
                return 1;
            }
            if (n == 2)
            {
                if (nums[0] == nums[1])
                {
                    return 1;
                }
                return 2;
            }

            int answer = 1;

            int currentIndex = 1;
            while (nums[currentIndex] == nums[currentIndex - 1])
            {
                currentIndex++;
                if (currentIndex == n)
                {
                    return answer;
                }
            }
            int previousDiff = nums[currentIndex] - nums[currentIndex - 1];
            ++answer;

            for (int i = currentIndex + 1; i < n; ++i)
            {
                if (nums[i] == nums[i - 1])
                {
                    continue;
                }
                else if ((nums[i] - nums[i - 1]) *previousDiff < 0)
                {
                    previousDiff = nums[i] - nums[i - 1];
                    ++answer;
                }
            }

            return answer;
        }
};