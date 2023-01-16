class Solution {
public:
    vector<vector<int>> construct2DArray1(vector<int>& original, int m, int n)
    {
        /*
        We create a 2D vector containing "n" elements each having the value "vector<int> (m, 0)".
        "vector<int> (m, 0)" means a vector having "m" elements each of value "0".
        Here these elements are vectors.
        
        vector<vector<int>> vec(m, vector<int> (n, 0));
        */
        
        if (m*n != original.size())
            return {};
        
        vector<vector<int>> vec(m, vector<int> (n,0));
        
        int count = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                vec[i][j] = original[count++];
            }
        }
        
        return vec;
    }
    
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        
        ios_base::sync_with_stdio(false); cin.tie(0); // i don't understand this line
        
        if (m*n != original.size())
            return {};
       
        vector<vector<int>> vec;
        vec.reserve(m);  // i don't understand this line
        
        vector<int>::const_iterator it = original.begin();
        
        for (int i=0; i<m; i++)
        {
            vector<int> temp(original.begin() + i*n, original.begin() + (1+i)*n);
            vec.push_back(temp);
        }
        
        return vec;
    }
};