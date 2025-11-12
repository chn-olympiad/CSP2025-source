#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],c[15];
int sum,minn = 1000000;
int main()
{
    freopen("road.in","r",radin);
    freopen("road.out","w",radout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        cin >> u[i] >> v[i];
        if (u[i]-v[i])
        {
            minn = u[i]-v[i];
        }
    }
    for (int j = 1;j <= k;j++)
    {
        cin >> k[i];
    }
    cout << minn;
    return 0;
}
