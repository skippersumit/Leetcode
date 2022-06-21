class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            priority_queue<int, vector < int>, greater < int>> minheap;

            for (int i = 0; i < heights.size() - 1; i++)
            {
                int diff = heights[i + 1] - heights[i];
                if (diff <= 0)
                {
                	//can move
                    continue;
                }
                else
                {
                    minheap.push(diff);	//store diff to use ladders

                   	//if ladder not available, then use bricks on small diff
                    if (minheap.size() > ladders)
                    {
                        bricks -= minheap.top();
                        minheap.pop();
                    }

                   	//no ladders and no bricks remaining
                    if (bricks < 0)
                    {
                        return i;
                    }
                }
            }

            return heights.size() - 1;
        }
};