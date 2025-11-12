#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=2e5+20,Maxm=5e6+10;
int n,q;
LL ans=0;
int nex[Maxn][500];
string s1[Maxn],s2[Maxn];
bool vis[Maxn],vis2[Maxn];
void init()
{
    for(int k=1;k<=n;k++)
    {
        nex[k][1]=0;
        int j=0;
        for(int i=2;i<(int)s1[k].length();i++)
        {
            while(j>0 && s1[i]!=s1[j+1]) j=nex[k][j];
            if(s1[i]==s1[j+1]) j++;
            nex[k][i]=j;
        }
    }
}
void dfs(string t1,string t2)
{
    if(t1==t2)
    {
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int len=(int)s1[i].length();
        for(int j=0,k=0;j+len<=(int)t1.length();j++)
        {
            //while(k>0 && t1[j]!=s1[i][k]) k=nex[i][k];
            bool flag=1;
            for(int p=j;p<=j+len-1;p++)
            {
                if(t1[p]!=s1[i][p-j])
                {
                    flag=0;
                    break;
                }
            }
            //if(t1[j]==s1[i][k]) k++;
            if(flag && !vis2[j])
            {
                for(int p=j;p<=j+len-1;p++) t1[p]=s2[i][p-j];
                //cout<<t1<<"\n";
                vis[i]=1;
                vis2[j]=1;
                dfs(t1,t2);
                for(int p=j;p<=j+len-1;p++) t1[p]=s1[i][p-j];
                vis[i]=0;
                vis2[j]=0;
            }
        }

    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        //cout<<s1[i]<<"\n";
        //cout<<s2[i]<<"\n";
    }
    init();
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        ans=0;
        memset(vis,0,sizeof(vis));
        dfs(t1,t2);
        printf("%lld\n",ans);
    }
    return 0;
}
