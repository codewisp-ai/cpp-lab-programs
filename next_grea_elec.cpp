#include <iostream>
#include <vector>
using namespace std;
//leetcode
class Solution
{ // TC:- O(n1*n2)
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            ans[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution s;
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}