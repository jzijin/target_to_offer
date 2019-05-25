#include <iostream>
using namespace std;

// 递归
int f1(int n)
{
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;
  if(n == 3)
    return 4;
  return f1(n-1) + f1(n-2) + f1(n-3);
}
// 动态规划
int f2(int n)
{
  // n >= 3
  int *tmp = new int[n+1];
  tmp[1] = 1;
  tmp[2] = 2;
  tmp[3] = 4;
  for(int i=4; i<n+1; ++i)
    tmp[i] = tmp[i-1] + tmp[i-2] + tmp[i-3];
  return tmp[n];
}

// 注意int不够存的情况
long long f3(int n)
{
  long long a = 1;
  long long b = 2;
  long long  c = 4;
  long long  d;
  for(int i=4; i<n+1; i++)
  {
    d = a + b + c;
    a = b;
    b = c;
    c = d;
  }
  return d;
}
int main()
{
  int num;
  cout << "请输入楼梯数量" << endl;
  cin >> num;
  // cout << f1(50) << endl;
  cout << "共有 "<< f3(num) << " 方式" << endl;
  return 0;
}
