class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        long long currtime=tasks[0][0],i=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>ans;
        while(!pq.empty() || i<n){
            while(i<n && tasks[i][0]<=currtime)
            {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(pq.empty()){
                currtime=tasks[i][0];
            }
            else{
                pair<int,int>p=pq.top();
                pq.pop();
                currtime+=p.first;
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};