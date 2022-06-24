class StockSpanner
{
    public:
       	//To Keep Track of Position of Each Stock
        int i = 0;

   	//Here I am using pair to store both index and price
    stack<pair<int, int>> s;
    StockSpanner() {}

    int next(int price)
    {
        i++;

       	//Here We will be finding next greater element to left

       	//If there are element in stack pop them until the element at top of stack is greater than price 
        while (!s.empty() && s.top().second <= price) s.pop();

       	//if no element in stack means next greater to left does not exist
        if (s.empty())
        {
            s.push({ i, price });
            return i;
        }

       	//if stack is not empty the element at top is ngl
        pair<int, int> temp = s.top();
        s.push({ i, price });
        return i - temp.first;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */