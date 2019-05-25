class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> tmp;
        int length = numbers.size()/2;
        for(auto i : numbers)
        {
            tmp[i] += 1;
        }
        
        for(auto i=tmp.begin(); i!=tmp.end(); ++i)
        {
            if(i->second > length)
                return i->first;
        }
        return 0;
    }
};