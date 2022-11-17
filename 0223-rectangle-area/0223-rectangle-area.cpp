class Solution
{
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
        {
            int a1 = (ax2 - ax1)*(ay2 - ay1);
            int b1 = (bx2 - bx1)*(by2 - by1);
            int x1 = min(bx2, ax2);
            int y1 = min(by2, ay2);
            int y2 = max(ay1, by1);
            int x2 = max(ax1, bx1);
            int f = (x1 - x2) *(y1 - y2);
            if ((x1 - x2) > 0 && (y1 - y2) > 0)
                return b1 + a1 - f;
            return b1 + a1;
        }
};