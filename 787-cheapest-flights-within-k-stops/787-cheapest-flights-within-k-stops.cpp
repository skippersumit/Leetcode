typedef pair<int, int> State;
class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector < int>> &flights, int src, int dst, int k)
        {
            vector<vector<pair<int, int>>> graph = create_graph(flights, n);

            queue<State> q;
            q.push({ src, 0 });
            vector<int> dist(n + 1, INT_MAX);
            dist[src] = 0;
            int level = 0;

            while (q.empty() == false && level <= k)
            {
                int qsize = q.size();
                for (int i = 0; i < qsize; i++)
                {
                   	// expand
                    auto[currNode, currDist] = q.front();
                    q.pop();

                   	// traverse its neighbours
                    for (pair<int, int> nei: graph[currNode])
                    {
                        int nextNode = nei.first;
                        int nextDist = nei.second;
                        if (currDist + nextDist < dist[nextNode])
                        {
                            dist[nextNode] = currDist + nextDist;
                            q.push({ nextNode, dist[nextNode] });
                        }
                    }
                }
                level++;
            }

            return dist[dst] == INT_MAX ? -1 : dist[dst];
        }

    vector<vector<pair<int, int>>> create_graph(vector<vector < int>> &flights, int n)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < flights.size(); i++)
        {
            int city1 = flights[i][0];
            int city2 = flights[i][1];
            int price = flights[i][2];
            graph[city1].emplace_back(city2, price);
        }
        return graph;
    }
};