#include<bits/stdc++.h>
#define int long long int

using namespace std;

ofstream setupOutput(string);
ifstream setupInput(string);

class Solution
{
public:
	string s;
	map<int, vector<vector<string>> > mp;

	bool is_palindrome(int i, int j)
	{
		while (i <= j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}

	vector<vector<string>> dp(int i)
	{
		if (i == s.size())
			return vector<vector<string>>();

		if (mp.count(i)) return mp[i];

		vector<vector<string>> ans;

		for (int j = i; j < s.size(); j++)
		{
			if (is_palindrome(i, j))
			{
				vector<vector<string>> res = dp(j + 1);
				string substring = s.substr(i, j - i + 1);

				for (auto &x : res)
				{
					x.insert(x.begin(), substring);
				}

				if (res.empty())
				{
					res.push_back({ substring });
				}

				for (auto x : res)
				{
					ans.push_back(x);
				}
			}
		}

		return mp[i] = ans;
	}
	vector<vector<string>> partition(string s)
	{
		this->s = s;
		return dp(0);
	}
};

int32_t main()
{
	string filePath = "C:\\Users\\Mukilan Arasu\\Documents\\Cplusplus_CodeBlocks\\Udemy_LearnCpp\\Udemy_DP_Algorithms_Master_course\\";

	ofstream fout = setupOutput(filePath + "output.txt");
	ifstream fin = setupInput(filePath + "input.txt");

	string s = "";
	fin >> s;

	while (!s.empty())
	{
		fout << "Working on: " << s << endl;
	
		Solution H;
		vector<vector<string>> res = H.partition(s);

		for (auto x : res)
		{
			for (auto y : x)
			{
				fout << y << " ";
			}
			fout << endl;
		}

		s = "";
		fin >> s; // or use getline(fin, s) instead of these last two lines
	}

	fout.close();
	fin.close();
	return 0;

}