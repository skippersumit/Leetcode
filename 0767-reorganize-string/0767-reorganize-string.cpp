class compare {
  public:
    bool operator()(pair<char, int> &a, pair<char, int> &b){
        return a.second < b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        int n = s.size();
        vector<int> count(26, 0);
        
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(count[i]) {
                pq.push({i + 'a', count[i]});
            }
        }
        
        string ans = "";
        auto toBeBlocked = pq.top();
        pq.pop();
        ans.push_back(toBeBlocked.first);
        toBeBlocked.second--;
        auto blocked = toBeBlocked;
        
        while(!pq.empty()){
            toBeBlocked = pq.top();
            pq.pop();
            ans.push_back(toBeBlocked.first);
            toBeBlocked.second--;
            if(blocked.second > 0) pq.push(blocked);
            blocked = toBeBlocked;
        }
        
        if(blocked.second > 0) return "";
        return ans;
    }
};