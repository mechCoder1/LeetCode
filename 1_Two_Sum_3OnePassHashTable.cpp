#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> TwoSum(vector<int>& nums, int target);
};

vector<int> Solution::TwoSum(vector<int>& nums, int target)
{
	vector <int> result = { -1, -1 }, result_i = { -1, -1 };
	map <int, int> m;
	int complement, i_idx;

	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
	{
		i_idx = int(distance(nums.begin(), i));
		complement = target - *i;

		if (m.find(complement) == m.end())
			m[*i] = i_idx;
		else
		{
			result_i = { i_idx, m[complement] };
			return result_i;
		}
	}

	return result_i;
}

int main()
{
	vector<int> in = { 1,2,2,3 }, out = { -1,-1 };
	int target = 5;

	Solution obj;

	out = obj.TwoSum(in, target);

	cout << out[0] << " " << out[1] << endl;
}
