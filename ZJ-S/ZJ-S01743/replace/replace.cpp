#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace awa
{
    const int N=2e5,M=5e6;

    int n,q;
    string s1[N+5],s2[N+5],t1[N+5],t2[N+5];

    inline bool check(const string& x)
    {
        int cnta=0,cntb=0;
        for(int i=0;i<x.size();++i)
            if(x[i]=='a') ++cnta;
            else if(x[i]=='b') ++cntb;
        return cntb==1&&cnta+cntb==x.size();    
    }
    inline int dis(const string& x)
    {
        for(int i=0;i<x.size();++i)
            if(x[i]=='b') return i;
        return x.size();
    }
    #define lowbit(x) (x)&(-(x))
    int tree[M+5];
    inline void add(int x){for(;x<=M;x+=lowbit(x)) ++tree[x];}
    inline int query(int x){int res=0;for(;x;x-=lowbit(x)) res+=tree[x];return res;}

    struct node{int id,x,y,z;}s[(N<<1)+5];int tot;
    inline bool cmp1(const node& x,const node& y){return (x.x^y.x)?x.x<y.x:x.id<y.id;}
    inline bool cmp2(const node& x,const node& y){return (x.y^y.y)?x.y<y.y:x.id<y.id;}

    #define mid ((l+r)>>1)
    int ans[N+5],cnt[(M<<1)+5];
    inline void solve(const int l,const int r)
    {
        if(l==r) return ;
        solve(l,mid),solve(mid+1,r);
        sort(s+l,s+mid+1,cmp2),sort(s+mid+1,s+r+1,cmp2);
        int j=l;
        for(int i=mid+1;i<=r;++i)
        {
            if(!s[i].id) continue;
            while(j<=mid&&s[j].y<=s[i].y)
                s[j].id?++j:++cnt[s[j++].z+M];
            ans[s[i].id]+=cnt[s[i].z+M];
        }while(j>l) --j,s[j].id?j:--cnt[s[j].z+M];
    }

    inline void work()
    {
        for(int i=1,x,y;i<=n;++i)
            x=dis(s1[i]),y=dis(s2[i]),
            s[++tot]={0,x,(int)s1[i].size()-x-1,x-y};
        for(int i=1,x,y;i<=q;++i)
        {
            if(t1[i].size()^t2[i].size()) continue;
            x=dis(t1[i]),y=dis(t2[i]),
            s[++tot]={i,x,(int)t1[i].size()-x-1,x-y};
        }sort(s+1,s+tot+1,cmp1),solve(1,tot);
        for(int i=1;i<=q;++i) cout<<ans[i]<<'\n';
    }

    inline void qwq()
    {
        cin>>n>>q;
        for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
        for(int i=1;i<=q;++i) cin>>t1[i]>>t2[i];

        bool sub=true;
        for(int i=1;i<=n;++i) sub&=check(s1[i]),sub&=check(s2[i]);
        for(int i=1;i<=q;++i) sub&=check(t1[i]),sub&=check(t2[i]);
        if(sub) return work();

        for(int i=1;i<=q;++i)
        {
            if(t1[i].size()^t2[i].size()){cout<<"0\n";continue;}
            int ans=0;
            for(int j=1;j<=n;++j)
            {
                for(int l=0;l+s1[j].size()<=t1[i].size();++l)
                {
                    bool flag=false;
                    for(int k=0;k<s1[j].size();++k)
                        if((s1[j][k]^t1[i][l+k])||(s2[j][k]^t2[i][l+k]))
                            {flag=true;break;}
                    if(flag) continue;
                    for(int k=l+s1[j].size();k<t1[i].size();++k)
                        if(t1[i][k]^t2[i][k]){flag=true;break;}
                    ans+=!flag;break;
                }
            }cout<<ans<<'\n';
        }
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    return awa::qwq(),0;
}