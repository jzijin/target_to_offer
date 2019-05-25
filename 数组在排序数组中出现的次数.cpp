class Solution {
public:
// TODO: 为什么这个解法会段错误呢？？？
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        int i=0;
        int j=data.size()-1;
        int mid;
        while(i<=j)
        {
            mid = i + (j-i)/2;
            if(data[mid] > k)
                j = mid -1;
            else if(data[mid] < k)
                i = mid + 1;
            else if(data[mid] == k)
                break;
        }
        int tmp = mid;
        while(1)
        {
            --tmp;
            if(tmp < 0)
                break;
            if(data[tmp] == k)
                ++count;
            else
                break;
        }
        while(1)
        {
            ++mid;
            if(mid ==data.size())
                break;
            if(data[mid] == k)
                count++;
            else
                break;    }
        return count;
        
    }
};

// 直接调用stl的解法
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {

auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
        
    }
};