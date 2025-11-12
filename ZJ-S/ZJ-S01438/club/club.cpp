#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
long long n,ans1=0;
int f[100][3];
int a[3]={0,0,0};
void dfs(int p,int ans)
{
    if(p==n)
    {
        ans1=max(ans,ans1);
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(a[i]<n/2)
        {
            a[i]+=1;
            dfs(p+1,ans+f[p][i]);
            a[i]-=1;
        }
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ans1=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>f[j][0]>>f[j][1]>>f[j][2];
        }
        dfs(0,0);
        cout<<ans1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
