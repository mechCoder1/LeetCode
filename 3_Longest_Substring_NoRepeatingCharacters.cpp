class Solution
{
    // Optimized Sliding Window
    // https://www.interviewbit.com/blog/longest-substring-without-repeating-characters/
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> chars(256);
        
        int left=0, right=0, res=0;
        
        while(right < s.length())
        {
            chars[s[right]]++;                  // register each character
            
            // if right index encounters a repetition, move left index until repeating character is eliminated
            while (chars[s[right]] > 1)
            {
                chars[s[left]]--;               // remove character to be eliminated from register
                left++;                         // move left index
            }
            
            res = max(res, right-left+1);
            right++;
        }
        
        return res;
    }
};

class Solution_SlidingWindow {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n=s.length();
        
        int res = 0;
        for (int i=0; i<n; i++)
        {
            vector<bool> visited(256);
            for (int j=i; j<n; j++)
            {
                if (visited[s[j]] == true)
                    break;
                else
                {
                    visited[s[j]] = true;
                    res = max(res, j-i+1);
                }
            }
            visited[s[i]] = false;
        }
        
        return res;
    }
};


class Solution_BruteForce {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n=s.length();
        
        int res = 0;
        for (int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if (checkNoRepetitions(s,i,j))
                {
                    res = max(res,j-i+1);
                }
            }
        }
        return res;
    }
    
    bool checkNoRepetitions(string& s, int start, int end)
    {
        vector<int> c(128);
        
        for(int i=start; i<=end; i++)
        {
            c[s[i]]++;
            
            if (c[s[i]] > 1)
                return false;
        }
        return true;
    }
};