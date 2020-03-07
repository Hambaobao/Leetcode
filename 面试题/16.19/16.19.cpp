class Solution {
public:
    vector<vector<int>> _land;
    vector<int> res;
    int row, col;

    int search(int i, int j) {
        if(i < 0 || i >= row || j < 0 || j >= col)      //如果超出边界
            return 0;
        if(_land[i][j] != 0)                            //如果不是水域
            return 0;
        _land[i][j] = 1;                                //查询过的地方作出标记

        int sum = 1;                                    //当前找到1片水域
        sum += search(i + 1, j);                        //东南西北
        sum += search(i - 1, j);
        sum += search(i, j + 1);
        sum += search(i, j - 1);

        sum += search(i + 1, j + 1);                    //东北东南西北西南
        sum += search(i + 1, j - 1);
        sum += search(i - 1, j + 1);
        sum += search(i - 1, j - 1);

        return sum;
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        _land = land;                                   //防止对外部land作出修改
        row = _land.size();                             
        col = _land[0].size();
        int val = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(_land[i][j] != 0)                    //不是水域
                    continue;
                val = search(i ,j);                     //搜索水域大小
                if(val != 0)                            //如果符合条件
                    res.push_back(val);
            }
        
        sort(res.begin(), res.end());                   //从小到大排序
        return res;
    }
};