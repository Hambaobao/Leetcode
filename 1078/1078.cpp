/*
    Solution1
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string temp_str;                //缓存字符串
        vector<string> split_str;       //存放用‘ ’切分出的字符串
        vector<string> res;             //存放输出结果
        
        for(int i = 0; i <= text.length(); i++)
        {
            if(text[i] != ' ' && text[i] != '\0')
            {
                temp_str.push_back(text[i]);
            }
            else
            {
                split_str.push_back(temp_str);      //遇到‘ ’或者‘\0’到达字符串末尾
                temp_str = "";                      //将缓存字符串压入split_str；
            }
        }
        
        for(int i = 0; i < split_str.size() - 2; i++)       //查找符合条件的单词
        {
            if(split_str[i] == first && split_str[i+1] == second)
                res.push_back(split_str[i+2]);
        }
        
        return res;
    }
};

/*
    Solution2
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string temp1, temp2, temp3;
        vector<string> res;
        
        ss >> temp1;
        while(ss >> temp2)
        {
            if(temp1 + temp2 == first + second)
            {
                ss >> temp3;
                if(temp3 != "")
                    res.push_back(temp3);
                temp1 = temp3;
                temp3 = "";
            }
            else
            {
                temp1 = temp2;
            }
        }
        
        return res;
    }
};