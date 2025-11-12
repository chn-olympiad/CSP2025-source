#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
struct edge
{
    int x,y,w;
};
edge a[1000005];
int b[100005];
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int f[100005];
int ans=0;
int find(int x)
{
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    f[find(x)]=find(y);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].w;
    }
    if(k==0)
    {
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            if(find(a[i].x)!=find(a[i].y))
            {
                merge(a[i].x,a[i].y);
                n--;
                ans+=a[i].w;
            }
            if(n==1)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            cin>>b[j];
            for(int l=1;l<=j-1;l++)
            {
                m++;
                a[m].x=j;
                a[m].y=l;
                a[m].w=b[j]+b[l]+c;
            }
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(find(a[i].x)!=find(a[i].y))
        {
            merge(a[i].x,a[i].y);
            n--;
            ans+=a[i].w;
        }
        if(n==1)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
