#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n = 0,m = 0,h = 0,l= 0,z = 1;
    cin>>n>>m;
    int  d = m*n;
    int a[d + 10] = {0,0};
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i = 2; i <= m*n;i++)
    {
        if(a[i] > a[1])
        {
            z += 1;
        }
    }
    l = z / n;
    if(z % n != 0)
    {
        l += 1;
    }
    h = z % n;
    if(l % 2 == 0)
    {
        h = n + 1 - h;
    }
    if(l > 1)
    {
        if(l % 2 == 0 && h == 0)
        {
            h = n;
        }
        else if(l % 2 != 0 && h == 0)
        {
            h = 1;
        }
    }
    else if(h == 0)
    {
        h = n;
    }
    cout<<l<<" "<<h;
    return 0;
}
