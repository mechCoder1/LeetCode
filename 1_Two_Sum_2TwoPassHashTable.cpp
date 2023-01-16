// https://leetcode.com/problems/two-sum/solution/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<int> TwoSum(vector<int>& nums, int target);
};

/*
// from: https://gist.github.com/luoxiaoxun/5938683

vector<int> Solution::TwoSum(vector<int> &numbers, int target)
{
	vector<int> ret(2);
	map<int,int> m;
	for(int i = 0; i < numbers.size(); i++)
	{
		if(m.find(numbers[i]) == m.end())
			m[target - numbers[i]] = i;
		else
		{
			if(m[numbers[i]] < i)
			{
				ret[0] = m[numbers[i]];
				ret[1] = i;
			}
		}
	}
	return ret;
}*/


	vector<int> Solution::TwoSum(vector<int>& nums, int target)
	{
		vector <int> result = { -1, -1 }, result_i = { -1, -1 };
		vector <int>::iterator i;
		
		map <int, int> m;           // nums_elem = m[nums_index];
		map <int, int>::iterator j;

		int complement;

		for (i = nums.begin(); i != nums.end(); i++)
		{
			i_idx  = int(distance(nums.begin(), i));
			complement = target - *i;
			j = m.find(complement);
			if (j == m.end())
				m.insert(make_pair(int(*i), i_idx));
			else
			{
				// result = { *i, complement };
				result_i = { i_idx, j->second };
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