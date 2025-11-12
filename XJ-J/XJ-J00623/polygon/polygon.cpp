#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin >>n;
    int a[1005];
    for (int i=1; i<=n; i++)
    {
        cin >>a[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (a[i]+a[i-1]>a[i+1])
        {
            sum++;
        }
        if (a[i]+a[i+1]>a[i-1])
        {
            sum++;
        }
        if (a[i]+a[i-1]+a[i-2]>a[+1])
        {
            sum++;
        }
        else
        {
            sum-1;
        }

    }
    cout <<sum-3;
    return 0;
}
