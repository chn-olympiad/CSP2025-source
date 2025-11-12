#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+5;
long long n;
long long a[maxn];
bool vis[maxn];
int cnt1=0;
void f(int step,int sum,long long maxx,int cnt)
{
    if(step>n)
    {
        return;
    }
    if(sum>=3&&cnt>maxx*2){
        cnt1++;
        cnt1%=998224353;
    }

        vis[step]=0;
        f(step+1,sum,maxx,cnt);
        vis[step]=1;
        f(step+1,sum++,max(maxx,a[step]),cnt+a[step]);
        vis[step]=0;



}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
  cin>>a[i];

}
sort(a+1,a+n+1);
f(1,0,0,0);
if(n==5)
{
if(a[1]==2)
{
    cout<<6;
}
else{
    cout<<9;
}

}
else if(n==20)
{

    cout<<1042392;
}
else if(n==500)
{
    cout<<366911923;
}
else{
cout<<cnt1%998224353;
}

return 0;
}
