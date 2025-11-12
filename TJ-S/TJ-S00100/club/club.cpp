#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    for (int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        int a[n+1][t+1];
        for (int z=1;z<=n+1;z++)
        {
            for (int j=1;j<=t+1;j++)
            {
                cin>>a[z][j];
            }
        }
        for (int z=1;z<=n+1;z++)
        {
            int ma=max(a[z][1],a[z][2]);
            for (int j=2;j<t+1;j++)
            {
                ma=max(ma,a[z][j]);
            }
            cout<<ma;
        }

    }

}

