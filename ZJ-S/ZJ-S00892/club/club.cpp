#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int ptc=1e5+10;
int dok[ptc][3];
vector<int>group[3];
struct thre3
{
    int val,id,to;
};
bool operator<(thre3 x1,thre3 x)
{
    return x1.val<x.val;
}
int max_idx(int p)
{
    int a=dok[p][0],b=dok[p][1],c=dok[p][2];
    if(a>=b&&a>=c)return 0;
    if(b>=a&&b>=c)return 1;
    else return 2;
}
int check(int n)
{
    for(int i=0;i<3;i++)
    {
        if(group[i].size()>n/2)return i;
    }
    return -1;
}
pii calc_dxd(int p)
{
    int a=0,b=1,c=2;
    if(dok[p][a]<dok[p][b])swap(a,b);
    if(dok[p][b]<dok[p][c])swap(b,c);
    if(dok[p][a]<dok[p][b])swap(a,b);
    return {b,dok[p][b]-dok[p][a]};
}
void fated(int xx0,int n,int& ans)
{
    priority_queue<thre3>pq;
    for(int x:group[xx0])
    {
        pii xr=calc_dxd(x);
        pq.push({xr.second,x,xr.first});
    }
    while(pq.size()>n/2)
    {
        thre3 rt=pq.top();
        pq.pop();
        group[rt.to].push_back(rt.id);
        ans+=rt.val;
    }
    group[xx0].clear();
}
int dxc(int a,int b)
{
    return 3-a-b;
}
void fatet(int xx1,int rxx,int n,int& ans)
{
    priority_queue<int>pq;
    for(int x:group[xx1])
    {
        pq.push(dok[x][rxx]-dok[x][xx1]);
    }
    while(pq.size()>n/2)
    {
        ans+=pq.top();
        pq.pop();
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3;i++)group[i].clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&dok[i][0],&dok[i][1],&dok[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int mx=max_idx(i);
            ans+=dok[i][mx];
            group[mx].push_back(i);
        }
        int xx0=check(n);
        if(xx0==-1)
        {
            printf("%d\n",ans);
            continue;
        }
        fated(xx0,n,ans);
        int xx1=check(n);
        if(xx1==-1)
        {
            printf("%d\n",ans);
            continue;
        }
        int rxx=dxc(xx0,xx1);
        fatet(xx1,rxx,n,ans);
        printf("%d\n",ans);
    }
    return 0;
}
