#include<bits/stdc++.h>
using namespace std;
int t,n[10],a[10005][5];
int sum[10];
int main()
{
    freopen("club.in","r",radin);
    freopen("club.out","w",radout);
    cin >> t;
    for (int i = 1;i <= t;i++)
    {
        cin >> n[i];
        for (int j = 1;j <= n[i];j++)
        {
            int maxx = -1;
            for (int k = 1;k <= 3;k++)
            {
                cin >> a[j][k];
                if (a[j][k] > maxx)
                {
                    maxx = a[j][k];
                }
            }
            sum[i] += maxx;
        }
    }
    for (int i = 1;i <= t;i++)
    {
        cout << sum[i] << endl;
    }
    return 0;
}
