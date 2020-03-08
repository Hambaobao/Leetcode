class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int len = light.size();
        int t = 0;
        int max_light = -1;
        int res = 0;
        while(t < len)
        {
            max_light = max(max_light, light[t] - 1);
            if(max_light == t)
                res++;
            t++;
        }
        return res;
    }
};