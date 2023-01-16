class Solution {
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int result = 0;
        
        int index = 0, n = s.size();
        
        // ignore whitespace
        for (; index < n && s[index] == ' '; index++);
        
        // look for sign
        if (index < n && s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (index < n && s[index] == '+')
            index++;
        
        // Traverse until not a digit
        for(; index < n && isdigit(s[index]); index++)
        {
            int digit = s[index] - '0';
            
            // Check overflow and underflow conditions.
            if((result > INT_MAX/10) || (result == INT_MAX/10 && digit > INT_MAX % 10))
            {
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                return sign==1? INT_MAX : INT_MIN;
            }
            
            // Append current digit to the result
            result = 10 * result + digit;
        }
        
        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign*result;
    }
};