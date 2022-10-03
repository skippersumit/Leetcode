class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int start = 0;
        int end = 1;
        int sum = 0;
        while(start < neededTime.size() && end < neededTime.size()) {
            if(colors[start] == colors[end]) {
                if(neededTime[start] > neededTime[end]) {
                    sum += neededTime[end];
                    end++;
                }
                else {
                    sum += neededTime[start];
                    start = end;
                    end++;
                }
            }
            else {
                start = end;
                end++;
            }
        }
        return sum;
    }
};