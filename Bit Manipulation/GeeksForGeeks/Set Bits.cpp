
** QUES - Set Bits **

class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        return __builtin_popcount(N);
    }
};