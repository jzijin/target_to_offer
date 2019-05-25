class Solution {
public:
    // 可能需要多次循环效率 可能比较低
    int FirstNotRepeatingChar(string str) {
        map<char, int> tmp;
        for(auto i : str)
        {
            tmp[i] += 1;
        }
        // 这边多弄一个字符串来存储简直是多此一举
        string s;
        for(auto i=tmp.begin(); i!=tmp.end(); ++i)
        {
            if(i->second == 1)
                s.push_back(i->first);
            
        }
        for(auto i=0; i<str.size(); ++i)
        {
            if(s.find(str[i]) <= s.size())
                return i;
        }
        return -1;
    }


};


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> tmp;
        for(auto i : str)
        {
            tmp[i] += 1;
        }
        
        for(auto i=0; i<str.size(); ++i)
        {
            if(tmp[str[i]] == 1)
                return i;
        }
        return -1;
    }
};