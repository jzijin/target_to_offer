// 这个是最简单的做法
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        for(int i=0; i<rotateArray.size(); ++i)
        {
            if(rotateArray[i+1] < rotateArray[i])
                return rotateArray[i+1];
        }
        return 0;
    }
};
// 加上了一点二分查找
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid;
        while(rotateArray[left] >= rotateArray[right])
        {
            if(right - left == 1)
            {
                mid = right;
                break;
            }
            mid = left + (right - left) / 2;
            // 大于左边的肯定大于右边的数
            if(rotateArray[mid] >= rotateArray[left])
                left = mid;
            else if(rotateArray[mid] <= rotateArray[right])
                right = mid;
        }
        return rotateArray[mid];
    }
};