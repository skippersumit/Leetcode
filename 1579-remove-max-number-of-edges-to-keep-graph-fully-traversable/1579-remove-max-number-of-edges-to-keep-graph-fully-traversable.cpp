class DSU
{
    public:
        vector<int> p;
        vector<int> r;

        DSU(int n)
        {
            r.resize(n);
            p.resize(n);

            for(int i=0;i<n;i++)
            {
                p[i] = i;
                r[i] = 0;
            }
        }

        int find(int x)
        {
            if(p[x] == x)
                return x;
            return p[x] = find(p[x]);
        }

        void makeUnion(int xx, int yy)
        {   int x = find(xx);
            int y = find(yy);
            if(x!=y)
            {
                if(r[x]>=r[y])
                {
                    p[y] = x;
                    r[x]+=r[y];
                }
                else
                {
                    p[x] = y;
                    r[y]+=r[x];            
                }
            }
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        
        DSU a(n+1),b(n+1);
        
        int ae = 0,be = 0, re = 0;
        
        for(auto &i:e)
        {
            int t = i[0];
            int n1 = i[1];
            int n2 = i[2];
            
            if(t ==3)
            {
                if(a.find(n1)!=a.find(n2) || b.find(n1)!=b.find(n2))
                {
                    a.makeUnion(n1,n2);
                    b.makeUnion(n1,n2);
                    ae++;
                    be++;
                }
                else
                    re++;
            }
        }
        for(auto &i:e)
        {
            int t = i[0];
            int n1 = i[1];
            int n2 = i[2];
            if(t == 1)
            {
                if(a.find(n1)!=a.find(n2))
                {
                    a.makeUnion(n1,n2);
                    ae++;
                }
                else
                    re++;

            }
            if(t == 2)
            {
                if(b.find(n1)!=b.find(n2))
                {
                    b.makeUnion(n1,n2);
                    be++;
                }
                else
                    re++;

            }
        }
        
        return (ae == n-1 && be == n-1)?re:-1;
    }
};