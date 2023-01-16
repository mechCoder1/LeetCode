#include <limits>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using std::max;
using std::vector;
using std::string;
using std::unordered_set;
class Solution
{
public:
	int longestSubstring(string s, int k)
	{
		int len = s.size();
		if (k < 1 || len < k)
			return 0;
		else if (k == 1)
			return len;
		vector<vector<int>> char_indexes(26, vector<int>());
		vector<int> valid_range(len, std::numeric_limits<int>::max());
		for (int i = 0; i < len; ++i) 
			char_indexes[s[i] - 'a'].push_back(i);
			for (auto& array : char_indexes)
			{
				int array_len = array.size();
				for (int i = 0, j = i + k - 1; j < array_len; ++i, ++j)
					valid_range[array[i]] = array[j];
			}
		return longestSubstring(s, k, 0, len, valid_range);
	}
private:
	int longestSubstring(const string& s, int k, int start, int end, const vector<int>& ranges)
	{
		if (start + k > end)
			return 0;
		int prev = start;
		int result = 0;
		unordered_set<char> chars;
		bool split_flag = false;
		for (int i = start; i < end; ++i)
		{
			if (chars.count(s[i]) == 0)
			{
				if (ranges[i] >= end)
				{
					split_flag = true;
					result = max(result, longestSubstring(s, k, prev, i, ranges));
					prev = i + 1;
					chars.clear();
				}
				else
				{
					chars.insert(s[i]);
				}
			}
		}
		if (split_flag)
			return max(result, longestSubstring(s, k, prev, end, ranges));
		return max(result, end - start);
	}
};