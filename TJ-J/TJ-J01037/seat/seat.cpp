#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int f;
    cin >> n >> m;
    int h=n*m;
    int a[h-1];
    for(int i=0;i<h;i++)
    {
        cin >> a[i];
        f=a[0];
    }
    sort(a+0,a+h);
    int y;
    for(int j=0;j<h;j++)
    {
        if(a[j]==f)
        {
            y=j;
            break;
        }
    }
    y=n*m-y;
    int v=y/n;
    if(y==v*n)
    {
        if(v%2==0)
        {
            cout << v << " " << 1;
            return 0;
        }
        else
        {
            cout << v << " " << n;
            return 0;
        }
    }
    if((y/n+1)%2==0)
    {
        cout << y/n+1 << " " << n-(y%n)+1;
    }
    if((y/n+1)%2!=0)
    {
        cout << y/n+1 << " " << y%n;
    }   
}

