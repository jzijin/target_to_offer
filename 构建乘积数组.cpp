class Solution {
  public:
    vector<int> multiply(const vector<int>& A) {
            vector<int> res(A.size());
            
            if(A.size() != 0)
            {
                        res[0] = 1;
                        for(int i=1; i<A.size(); ++i)
                        {
                                        res[i] = res[i-1] * A[i-1];
                                    }
                        int temp = 1;
                        for(int j=A.size()-2; j>=0; --j)
                        {
                                        temp *= A[j+1];
                                        res[j] *= temp;
                                    }
                    }
            return res;
        }
};
