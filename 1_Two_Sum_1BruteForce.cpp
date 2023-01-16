% https://leetcode.com/problems/two-sum/solution/

#include<iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector <int> result = { -1, -1 }, result_i = { -1, -1 };
	vector <int>::iterator i, j;
	
	for (i = nums.begin(); i != nums.end(); i++)
	{
		for (j = i + 1; j != nums.end(); j++)
		{
			if (*j == target - *i)
			{
				result = { *i, *j };
				result_i = { int(distance(nums.begin(), i)), int(distance(nums.begin(), j)) };
				return result_i;
			}
		}
	} 
	return result_i;
}

int main()
{
	Solution obj;

	vector<int> in = { 2, 7, 11, 1 }, out = { -1,-1 };

	out = obj.twoSum(in, 9);

	// cout << out[0] << " " << out[1] << endl;

	vector <int>::iterator i;
	for (i = out.begin(); i != out.end(); i++)
		cout << *i << " ";
	cout << endl;
	
}