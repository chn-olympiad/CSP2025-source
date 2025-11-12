#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans;
int a[100005][5];
int pre[100005];
int b[100005];
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int p,int num1,int num2,int num3,int sum)
{
    if(p==n+1)
    {
        if(num1<=n/2&&num2<=n/2&&num3<=n/2)ans=max(ans,sum);
        return;
    }
    if(sum+pre[n]-pre[p-1]<=ans)return;
    if(num1>n/2||num2>n/2||num3>n/2)return;
    dfs(p+1,num1+1,num2,num3,sum+a[p][1]);
    dfs(p+1,num1,num2+1,num3,sum+a[p][2]);
    dfs(p+1,num1,num2,num3+1,sum+a[p][3]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool flag1=1;
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
            }
            b[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0)flag1=0;
            pre[i]=pre[i-1]+max(max(a[i][1],a[i][2]),a[i][3]);
        }
        //cout<<f[n];
        ans=0;
        if(flag1)
        {
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                ans+=b[i];
            }
        }
        else if(n<=30)dfs(1,0,0,0,0);
        else
        {
            for(int i=1;i<=n;i++)
            {
                ans+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
