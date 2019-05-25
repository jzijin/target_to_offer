class Solution
{
public:
    bool isok(vector<bool> marked, char *matrix, int r, int c, int rows, int cols, char *a, int index)
    {

        int tmp = r * cols + c;
        if (r < 0 || r >= rows || c < 0 || c >= cols || matrix[tmp] != a[index] || marked[tmp] == true)
            return false;
        if (index == strlen(a) - 1)
            return true;
        marked[tmp] = 1;
        if (isok(marked, matrix, r - 1, c, rows, cols, a, index + 1) 
            || isok(marked, matrix, r + 1, c, rows, cols, a, index + 1) 
            || isok(marked, matrix, r, c - 1, rows, cols, a, index + 1) 
            || isok(marked, matrix, r, c + 1, rows, cols, a, index + 1))
        {
            return true;
        }
        marked[tmp] = false;
        return false;
    }
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        // 用一个vector 数组来存储当前结点是否被访问过。
        vector<bool> marked(rows * cols, false);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (isok(marked, matrix, i, j, rows, cols, str, 0))
                    return true;
            }
        }
        return false;
    }
};