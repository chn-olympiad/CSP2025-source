#include <iostream>
using namespace std;
int n,m,a[1005],b,c,d,e;
int main()
{
    //freget("seat.in","w",stdin);
    //freget("seat.out","s",stdout);
    cin>>n>>m>>a[1];
    b=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m*n;i++)
    {
        if(a[i]<a[i+1])
        {
            c=a[i];
            a[i]=a[i+1];
            a[i+1]=c;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==b)
        {
            e=i/n;
            if(e%2==1)
            {
                d=i%n;
            }
            else
            {
                d=n+1-i%n;
            }
        }
    }
    cout<<e<<" "<<d;
}
