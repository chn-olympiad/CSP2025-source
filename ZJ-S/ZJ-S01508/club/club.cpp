#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int num=0,sign=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?sign=-1:sign=1,ch=getchar();
    while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0?num:-num;
}
const int MAXN=1e5+8;
int T,n,cnt,head=1,tail,ans;
int mp[MAXN][4],v[4][MAXN];
int vis[MAXN];
struct node
{
    int val,id,pos;
}a[MAXN*3];
struct Queue
{
    int val,id,pos;
}q[MAXN];
bool cmp(node x,node y)
{
    if(x.val!=y.val) return x.val<y.val;
    if(x.id!=y.id) return x.id<y.id;
    return x.pos<y.pos;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--)
    {
        ans=0,cnt=0;
        memset(vis,0,sizeof(vis));
        memset(v,0,sizeof(v));
        n=read();
        for(int i=1;i<=n;i++)
        {
            for(int j=1,x;j<=3;j++)
            {
                cin>>x;
                a[++cnt].val=x;
                a[cnt].id=i;
                a[cnt].pos=j;
                mp[i][j]=x;
            }
        }
        sort(a+1,a+cnt+1,cmp);
        memset(vis,0,sizeof(vis));
        for(int i=cnt;i>=1;i--)
        {
            if(vis[q[i].id]) continue;
            vis[q[i].id]=true;


            if((v[q[i].pos][0]+1)*2>n)
            {
                for(int j=1;j<=3;j++)
                {
                    if(q[i].pos==j) continue;
                    mx=max(mx,(ans+mp[v[q[i].pos][v[q[i].pos][0]]][j]+q[i].val
                       -mp[v[q[i].pos][v[q[i].pos][0]]][q[i].pos]));
                    if(mx>ans) ans=mx,v[q[i].pos][v[q[i].pos][0]]=q[i].id;
                }
            }
            else
            {
                ans+=q[i].val;
                v[q[i].pos][++v[q[i].pos][0]]=q[i].id;
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
