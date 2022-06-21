class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(int i=0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }
        
        while(maxHeap.size() > 1){
            int stoneOne = maxHeap.top();maxHeap.pop();
            int stoneTwo = maxHeap.top();maxHeap.pop();
            
            if(stoneOne != stoneTwo)
                maxHeap.push(stoneOne-stoneTwo);
        }
        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};