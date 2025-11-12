#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105]={};
    cin>>n>>m;
    int s=n*m,b;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+s+1,cmp);
    for(int i=1;i<=s;i++)
    {
        if(b==a[i])
        {
            int id=i,x,y;
            if(id%n==0)x=id/n;
            else x=id/n+1;
            if(x%2==0)
            {
                if(id%n==0)y=1;
                else y=n-id%n+1;
            }
            else
            {
                if(id%n==0)y=n;
                else y=id%n;
            }
            cout<<x<<' '<<y;
            return 0;
        }
    }
}
