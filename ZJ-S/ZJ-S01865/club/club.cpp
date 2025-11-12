/*
cho max
find num > n / 2
sort by red to sec
let small to tri
*/
#include <bits/stdc++.h>
using namespace std;

#define cinf 0x3fffffff
long long qread()
{
    long long res = 0;char ch = getchar();
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar())
        res = (res << 1) + (res << 3) + ch - '0';
    return res;
}
#define maxn 100005
int csyy , len;long long num[maxn][3] , cho[maxn][3] , red[maxn] , res;
int mem[3];
bool cmp1(int a , int b){return mem[a] > mem[b];}
int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    csyy = qread();
    while(csyy--)
    {
        len = qread();
        for(int i = 0;i < len;i++)
            {num[i][0] = qread();num[i][1] = qread();num[i][2] = qread();}
        for(int i = 0;i < len;i++)
        {
            mem[0] = num[i][0] , mem[1] = num[i][1] , mem[2] = num[i][2];
            cho[i][0] = 0 , cho[i][1] = 1 , cho[i][2] = 2;
            sort(cho[i] , cho[i] + 3 , cmp1);
            // cout << cho[i][0] << '\n';
        }
        memset(mem , 0 , sizeof(mem));
        for(int i = 0;i < len;i++)mem[cho[i][0]]++;
        int aim = -1;
        if(mem[0] > (len >> 1))aim = 0;
        else if(mem[1] > (len >> 1))aim = 1;
        else if(mem[2] > (len >> 1))aim = 2;
        // cout << aim << '\n';
        res = 0;
        for(int i = 0;i < len;i++)res += num[i][cho[i][0]];
        if(aim != -1)
        {
            for(int i = 0;i < len;i++)
                if(cho[i][0] == aim)red[i] = num[i][cho[i][0]] - num[i][cho[i][1]];
                else red[i] = cinf;
            sort(red , red + len);
            // for(int i = 0;i < len;i++)cout << red[i] << '\n';
            for(int i = 0;i < mem[aim] - (len >> 1);i++)
                res -= red[i];
        }
        printf("%lld\n" , res);
    }
    return 0;
}