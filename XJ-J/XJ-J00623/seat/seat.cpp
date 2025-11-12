#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int maxx=INT_MIN;
    cin >>n>>m;
    int a[1005];
    int b[1005][1005];
    for (int i=1; i<=n*m; i++) cin >>a[i];
    for (int i=1; i<=n*m; i++)
    {
        if (maxx<a[i])
        {
            maxx=a[i];
        }
    }
    for (int i=1; i<=n*m; i++)
    {

       if (a[1]<maxx)
       {
           cout <<b[i][i+1];
       }
    }
    return 0;
}
