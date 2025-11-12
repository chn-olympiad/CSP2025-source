#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int n;
int a[5][100005];
int ans;
int s[100005];
int d[100005];
void dfs(int step,int cnt1,int cnt2,int cnt3,int cnt)
{
    if(cnt1>n/2)return;
    if(cnt2>n/2)return;
    if(cnt3>n/2)return;
    if(cnt+s[step]<=ans)return;
    if(step>n)
    {
        ans=max(ans,cnt);
        return;
    }
    dfs(step+1,cnt1+1,cnt2,cnt3,cnt+a[1][step]);
    dfs(step+1,cnt1,cnt2+1,cnt3,cnt+a[2][step]);
    dfs(step+1,cnt1,cnt2,cnt3+1,cnt+a[3][step]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        bool flag1=true;
        bool flag2=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[2][i]!=0&&a[3][i]!=0)flag1=false;
            if(a[3][i]!=0)flag2=false;
        }
        if(n<=30)
        {
            for(int i=n;i>=1;i--)
            {
                s[i]=s[i+1]+max(a[1][i],max(a[2][i],a[3][i]));
            }
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
            continue;
        }
        else if(flag1==true)
        {
            sort(a[1]+1,a[1]+n+1);
            for(int i=n;i>=n/2+1;i--)
            {
                ans+=a[1][i];
            }
            cout<<ans<<endl;
            continue;
        }
        else if(flag2==true)
        {
            for(int i=1;i<=n;i++)
            {
                ans+=a[1][i];
                d[i]=a[2][i]-a[1][i];
            }
            sort(d+1,d+n+1);
            for(int i=n;i>=n/2+1;i++)
            {
                ans+=d[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else
        {
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
