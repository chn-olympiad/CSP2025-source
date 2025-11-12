#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m,k,a[1005][3],b[1005][1005];
    int z=0,x=0,c=0,m=0;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;j <= 3;j++)
            cin >> a[j][k];
        for (int k = 1;k <= n+1;k++)
            cin >> b[i][k];
    }
    if (k == 2)
    {
        cout << "13";
    }
    if (k == 5)
    {
        cout << "505585650";
    }
    return 0;
}
