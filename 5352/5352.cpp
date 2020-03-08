class Solution {
public:
    string generateTheString(int n) {
        string res = "\0";
        for(int i = 0; i < n - 1; i++)
            res += 'a';
        if(n % 2)
            res += 'a';
        else
            res += 'z';

        return res;
    }
};