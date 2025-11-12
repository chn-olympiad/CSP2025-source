#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100000],b,c,d[100000],e=1,f=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=n*m;
    for(int i=1; i<=b; i++)
    {
        cin>>a[i];
    }
    c=a[1];
    for(int i=1; i<=b; i++)
    {
        d[a[i]]++;
    }
    for(int i=100; i>=0;)
    {
        if(d[i]!=0)
        {
            if(i==c)
            {
                cout<<e<<" "<<f;
                return 0;
            }
            d[i]--;
            if(f==m&&e%2==1)
            {
                e++;
            }
            else if(f<m&&e%2==1)
            {
                f++;
            }
            else
            if(f==1&&e%2==0)
            {
                e++;
            }
            else if(f>1&&e%2==0)
            {
                f--;
            }

        }
        else
            i--;
    }
    return 0;
}