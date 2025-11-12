/*
f(a , b) = 
*/
#include <bits/stdc++.h>
using namespace std;

long long qread()
{
    long long res = 0;char ch = getchar();
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar())
        res = (res << 1) + (res << 3) + ch - '0';
    return res;
}
#define maxn 502
#define modn 998244353
int len , aim;
char dif[maxn];int pai[maxn];long long res;
int mem[20];
bool check()
{
    int cnt = 0 , cnt2 = 0;
    for(int i = 0;i < len;i++)
    {
        if(dif[i] == '0' || (cnt >= pai[mem[i]]))cnt++;
        else cnt2++;
        if(cnt2 == aim)return true;
    }
    return false;
}
int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    len = qread();aim = qread();
    scanf("%s" , dif);
    // printf("%s\n" , dif);
    for(int i = 0;i < len;i++)pai[i] = qread();
    if(len <= 20)
    {
        for(int i = 0;i < len;i++)mem[i] = i;
        if(check())res = 1;
        while(next_permutation(mem , mem + len))
        {
            if(check())res++;
        }
        printf("%lld\n" , res);
        return 0;
    }
    return 0;
}
