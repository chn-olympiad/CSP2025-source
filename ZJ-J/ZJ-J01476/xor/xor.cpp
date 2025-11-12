#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int sign=1,num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?sign=-1:sign=1,ch=getchar();
    while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0?num:-num;
}
const int MAXN=5e5+8;
int n,k,cnt;
int a[MAXN],dp[MAXN];
struct SegtreeNode
{
    int sum;
    SegtreeNode operator+(const SegtreeNode& rhs) const
    {
        return {sum^rhs.sum};
    }
};
struct SegmentTree
{
    int sz=1,lb[MAXN<<1],rb[MAXN<<1],lc[MAXN<<1],rc[MAXN<<1];
    SegtreeNode tr[MAXN<<1];
    inline void push_up(int u) { tr[u]=tr[lc[u]]+tr[rc[u]]; }
    void build(int u,int l,int r,int vals[])
    {
        lb[u]=l,rb[u]=r;
        if(l==r)
        {
            tr[u].sum=vals[l];
            return;
        }
        int mid=(l+r)>>1;
        build(lc[u]=++sz,l,mid,vals);
        build(rc[u]=++sz,mid+1,r,vals);
        push_up(u);
    }
    SegtreeNode query(int u,int l,int r)
    {
        if(l>r||l>rb[u]||r<lb[u]) return {0};
        if(l<=lb[u]&&rb[u]<=r) return tr[u];
        return query(lc[u],l,r)+query(rc[u],l,r);
    }
}segtr;
struct node
{
    int l,r;
}syq[MAXN];
bool cmp(node x,node y)
{
    if(x.l==y.l) return x.r<y.r;
    return x.l<y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i]=read();
    segtr.build(1,1,n,a);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(segtr.query(1,i,j).sum==k) syq[++cnt]={i,j};
    sort(syq+1,syq+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) dp[i]=1;
    for(int i=2;i<=cnt;i++)
        for(int j=1;j<i;j++)
            if(syq[j].r<syq[i].l) dp[i]=max(dp[i],dp[j]+1);
    int ans=0;
    for(int i=1;i<=cnt;i++) ans=max(ans,dp[i]);
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
