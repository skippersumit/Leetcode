class Solution {
public:
    string pushDominoes(string dom) {
        vector<int> l(dom.size()), r(dom.size());
        
        int f = 0, cnt = 1;
        for(int i=dom.size()-1; i>=0; i--) {
            if(dom[i] == 'L') f = 1, cnt = 1;
            else if(dom[i] == 'R') f = 0, cnt = 1;
            else if(dom[i] == '.' && f) l[i] = cnt++;
        }
        
        f = 0, cnt = 1;
        for(int i=0; i<dom.size(); i++) {
            if(dom[i] == 'R') f = 1, cnt = 1;
            else if(dom[i] == 'L') f = 0, cnt = 1;
            else if(dom[i] == '.' && f) r[i] = cnt++;
        }
        
        string ans = dom;
        for(int i=0; i<dom.size(); i++) {
            if(dom[i] == '.') {
                if(!l[i] && r[i]) {ans[i] = 'R'; continue;}
                if(l[i] && !r[i]) {ans[i] = 'L'; continue;}
                
                if(l[i] == r[i]) {ans[i] = '.'; continue;}
                else {ans[i] = l[i] < r[i] ? 'L' : 'R'; continue;}
            }
        }
        return ans;
    }
};