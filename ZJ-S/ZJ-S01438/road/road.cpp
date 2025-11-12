#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int ans=INT_MAX;
struct node
{
    int v,u,w;
};
vector<node> v1;
int c[10][10000];
int b[10000]={0};
int cmd(node n1,node n2)
{
    return n1.w<n2.w;
}
int findf(int t)
{
    if(t==b[t])
    {
        return t;
    }
    b[t] = findf(b[t]);
    return b[t];
}
void unity(int x,int y)
{
    b[findf(x)]=b[y];
}
void mintree(vector<int> v2)
{
    int ans1=0;
    vector<node> v3=v1;
    for(int i=0;i<v2.size();i++)
    {
        ans1+=c[v2[i]][0];
        for(int j=0;j<n;j++)
        {
            node na;
            na.u=v2[i];
            na.v=j;
            na.w=c[v2[i]][j+1];
            v3.push_back(na);
        }
    }
    sort(v3.begin(),v3.end(),cmd);
    for(int i=0;i<v3.size();i++)
    {
        b[i]=i;
    }
    for(int i=0;i<v3.size();i++)
    {
        if(findf(v1[i].u)!=findf(v1[i].v))
        {
            ans1+=v1[i].w;
        }
    }
    ans=min(ans1,ans);
    return;
}
void dfs(int p,vector<int> v2)
{
    if(p==k)
    {
        mintree(v2);
        return;
    }
    for(int i=0;i<2;i++)
    {
        if(i==0)
        {
            dfs(p+1,v2);
        }
        else
        {
            vector<int>v3;
            v3.push_back(p);
            dfs(p+1,v3);
        }
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        node no;
        cin>>no.u>>no.v>>no.w;
        v1.push_back(no);
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    vector<int> vo;
    dfs(0,vo);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
