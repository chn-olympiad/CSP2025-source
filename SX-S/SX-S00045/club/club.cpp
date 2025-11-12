#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n[1005],a[1005][3];
    int z=0,x=0,c=0,m=0;
    cin >> t;
    for (int i = 1;i <= t;i++)
    {
        cin >> n[i];
        for (int j = 1;j <= n[i];j++)
            for (int k = 1;k <= 3;k++)
                cin >> a[j][k];
    }
    for (int i = 1;i <= t;i++)
    {
        for (int j = 1;j <= n[i];j++)
        {
            if ((a[j][1] > a[j][2]) && (a[j][2] > a[j][3]))
            {
                if(z < n/2)
                {
                    z++;
                    m += a[j][1];
                }
                else if(x < n/2)
                {
                    x++;
                    m += a[j][2];
                }
            }
            else if ((a[j][1] > a[j][3]) && (a[j][3] > a[j][2]))
            {
                if(z < n/2)
                {
                    z++;
                    m += a[j][1];
                }
                else if(c < n/2)
                {
                    c++;
                    m += a[j][3];
                }
            }
            else if ((a[j][2] > a[j][3]) && (a[j][3] > a[j][1]))
            {
                if(x < n/2)
                {
                    x++;
                    m += a[j][2];
                }
                else if(c < n/2)
                {
                    c++;
                    m += a[j][3];
                }
            }
            else if ((a[j][2] > a[j][1]) && (a[j][1] > a[j][3]))
            {
                if(x < n/2)
                {
                    x++;
                    m += a[j][2];
                }
                else if(z < n/2)
                {
                    z++;
                    m += a[j][1];
                }
            }
            else if ((a[j][3] > a[j][2]) && (a[j][2] > a[j][1]))
            {
                if(c < n/2)
                {
                    c++;
                    m += a[j][3];
                }
                else if(x < n/2)
                {
                    x++;
                    m += a[j][2];
                }
            }
            else if ((a[j][3] > a[j][1]) && (a[j][1] > a[j][2]))
            {
                if(c < n/2)
                {
                    c++;
                    m += a[j][3];
                }
                else if(z < n/2)
                {
                    z++;
                    m += a[j][1];
                }
            }
        }
    }
    cout << m;
    return 0;
}
