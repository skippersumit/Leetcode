class Solution
{
    public:
        static bool mycomp(vector<int> &A, vector<int> &B)
        {
            if (A[1] < B[1])
                return true;
            return false;
        }
    int scheduleCourse(vector<vector < int>> &courses)
    {
        sort(courses.begin(), courses.end(), mycomp);
        int time = 0, x;
        priority_queue<int> pq;

        for (auto course: courses)
        {
            if (time + course[0] <= course[1])
            {
                time += course[0];
                pq.push(course[0]);
            }
            else
            {
                if (!pq.empty() and pq.top() > course[0])
                {
                    x = pq.top();
                    pq.pop();
                    time -= x;
                    time += course[0];
                    pq.push(course[0]);
                }
            }
        }

        return pq.size();
    }
};