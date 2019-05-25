class Solution
{
public:
    int get_num(int num, int num2)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        while (num2)
        {
            sum += num2 % 10;
            num2 /= 10;
        }
        return sum;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> marked(rows, vector<bool>(cols, false));
        queue<int> r;
        queue<int> c;
        r.push(0);
        c.push(0);
        int count = 0;
        int add1;
        int add2;
        if (get_num(0, 0) <= threshold)
        {
            marked[0][0] = true;
            ++count;
        }
        while (!r.empty())
        {
            add1 = r.front();
            add2 = c.front();
            r.pop();
            c.pop();
            if (add1 - 1 >= 0 && !marked[add1 - 1][add2])
            {

                if (get_num(add1 - 1, add2) <= threshold)
                {
                    r.push(add1 - 1);
                    c.push(add2);
                    marked[add1 - 1][add2] = true;
                    ++count;
                }
            }
            if (add1 + 1 < rows && !marked[add1 + 1][add2])
            {

                if (get_num(add1 + 1, add2) <= threshold)
                {
                    r.push(add1 + 1);
                    c.push(add2);
                    marked[add1 + 1][add2] = true;
                    ++count;
                }
            }
            if (add2 - 1 >= 0 && !marked[add1][add2 - 1])
            {

                if (get_num(add1, add2 - 1) <= threshold)
                {
                    r.push(add1);
                    c.push(add2 - 1);
                    marked[add1][add2 - 1] = true;
                    ++count;
                }
            }
            if (add2 + 1 < cols && !marked[add1][add2 + 1])
            {

                if (get_num(add1, add2 + 1) <= threshold)
                {
                    r.push(add1);
                    c.push(add2 + 1);
                    marked[add1][add2 + 1] = true;
                    ++count;
                }
            }
        }
        return count;
    }
};