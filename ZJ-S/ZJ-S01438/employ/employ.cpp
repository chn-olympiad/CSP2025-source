#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1;
int a[500];
int b[500]={0};
int c[500]={0};
long long ans=0;
void dfs(int p,int sum)
{
    if(sum>=m)
    {
        ans++;
        return;
    }
    if(p==n)
    {
        return;
    }
    int k=(int)s1[p]-48;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0&&b[p]<a[i])
        {
            c[i]=1;
            dfs(p+1,sum+k);
            c[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.ans","w",stdout);
    cin>>n>>m;
    cin>>s1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+1-(int)s1[i-1]+48;
    }
    dfs(0,0);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
