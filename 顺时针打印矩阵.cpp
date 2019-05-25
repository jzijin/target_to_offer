class Solution
{
        // TODO: 写的有点麻烦 云里雾里
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> target;
        //int circle=((row<collor?row:collor)-1)/2+1;
        int times = ((row < col ? row : col) - 1) / 2 + 1;
        int tmp = 0;
        while (tmp != times)
        {
            int i = tmp, j = tmp;
            for (; j < col - tmp; ++j)
                target.push_back(matrix[i][j]);
            //cout << "i=" << i << "j=" << j;
            j = col - tmp - 1;
            for (i = i + 1; i < row - tmp; ++i)
                target.push_back(matrix[i][j]);
            i = row - tmp - 1;
            if (j != tmp)
            {
                if (i != tmp)
                {
                    for (j = j - 1; j >= tmp; --j)
                        target.push_back(matrix[i][j]);
                }

                j = tmp;
                for (i = i - 1; i > tmp; --i)
                    target.push_back(matrix[i][j]);
            }

            ++tmp;
            //return target;
        }
        return target;
    }
};