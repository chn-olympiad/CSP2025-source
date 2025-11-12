#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
        cin>>a[i];
}
int sum=a[1];
int x=1,y=1;
bool k=0;
sort(a+1,a+n*m+1,cmp);
int cnt=0;
for(int i=1;i<=n*m;i++)
{
    if(sum==a[i])
    {
        cnt=i;

    }

}
if(((cnt+n-1)/n)%2==1)
{
    x=cnt%n;
    y=(cnt+n-1)/n;
    if(x==0)
    {

        x=n;
    }

}
else{
     y=(cnt+n-1)/n;
     x=n-cnt%n+1;
}



    cout<<y<<" "<<x;
return 0;
}
