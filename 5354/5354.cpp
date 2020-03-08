class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0; 

        for(int i = 0; i < n; i++)          //遍历所有员工
        {
            if(informTime[i] == 0)          //从叶子结点向上回溯
            {
                int temp = 0;
                int index = manager[i];
                while(index != -1)          //直到总负责人
                {
                    temp += informTime[index];
                    index = manager[index];
                }

                res = max(res, temp);       //记录最长时间
            }
        }

        return res;
    }
};