class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() == 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int cnt = 0;
        int cnt_need = 0;
        for(int i=0; i<numbers.size(); i++)
        {
            if(numbers[i] == 0)
                ++cnt;
            else if(i+1<5)
            {
                if(numbers[i] == numbers[i+1])
                    return false;
                cnt_need += numbers[i+1]-numbers[i]-1;
            }
        }
        return cnt_need <= cnt;
    }
};