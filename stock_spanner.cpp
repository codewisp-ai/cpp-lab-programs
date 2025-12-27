#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    // stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    // solution
    vector<int> span(prices.size(), 0);
    stack<int> st;
    for (int i = 0; i < prices.size(); i++)
    {
        while (st.size() > 0 && prices[st.top()] <= prices[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - st.top();
        }
        st.push(i);
    }
    // printing answer values
    for (int val : span)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;

    // TC :- O(n)!!!
}