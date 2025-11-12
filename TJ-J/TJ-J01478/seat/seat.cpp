#include<iostream>
#include<cstdio>
using namespace std;

int b[10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y,cnt=1;
    cin>> n>>m;
    for(int i=0;i<=n*m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<=m*n;i++)
    {
        if(b[i]>b[0])
        {
            cnt++;
        }
    }
    if(cnt%n==0)
    {
        x=cnt/n;
    }
    if(cnt%n!=0)
    {
        x=(cnt/n+1);
    }
    if(x%2==1)
    {
        if(cnt%n!=0)
        {
            y=cnt%n;
        }
        if(cnt%n==0)
        {
            y=n;
        }
    }
    if(x%2==0)
    {
        if(cnt%n!=0)
        {
            y=(n-cnt%n+1);
        }
        if(cnt%n==0)
        {
            y=1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
