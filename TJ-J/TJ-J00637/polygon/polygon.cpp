#include <bits/stdc++.h>
using namespace std;
int n,a[5500];
long long cnt;
long long g,f[5500]={1};
void add(int m)
{
    cnt+=g/f[m];
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        g*=i;
        f[i]=f[i-1]*i;
    }
    for (int i = 3;i <= n;i++)
    {
        add(i);
    }
    cout << cnt;
    return 0;
}
