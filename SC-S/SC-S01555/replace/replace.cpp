#include<bits/stdc++.h>
using namespace std;

using ull=unsigned long long;
static constexpr const ull P=29;
int n,q,cnt,trie[6000001][27],Ans[200001],dfn[6000001],siz[6000001],cntdfn,bit[6000001];
string s1,s2,t1,t2;
map<pair<ull,ull>,int>rtl,rtr;
vector<int>ano[6000001];
vector<pair<int,int>>qry[6000001];

void add(int l,int r,int v)
{
    for(int x=r;x;x-=x&-x)
        bit[x]+=v;
    for(int x=l-1;x;x-=x&-x)
        bit[x]-=v;
}

int query(int t)
{
    int ans=0;
    for(int x=t;x<=cnt;x+=x&-x)
        ans+=bit[x];
    return ans;
}

void dfs(int u)
{
    dfn[u]=++cntdfn;
    siz[u]=1;
    for(int i=0;i<26;i++)
        if(trie[u][i])
            dfs(trie[u][i]),
            siz[u]+=siz[trie[u][i]];
}

void solve(int u)
{
    for(int v:ano[u])
        add(dfn[v],dfn[v]+siz[v]-1,1);
    for(auto[v,x]:qry[u])
        Ans[x]+=query(dfn[v]);
    for(int i=0;i<26;i++)
        if(trie[u][i])
            solve(trie[u][i]);
    for(int v:ano[u])
        add(dfn[v],dfn[v]+siz[v]-1,-1);
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        if(s1==s2)
            continue;
        int k=s1.size(),l=0,r=k-1;
        for(int i=0;i<k;i++)
            if(s1[i]!=s2[i])
            {
                l=i;
                break;
            }
        for(int i=k-1;i>=0;i--)
            if(s1[i]!=s2[i])
            {
                r=i;
                break;
            }
        ull H1=0,H2=0;
        for(int i=l;i<=r;i++)
            H1=H1*P+s1[i]-'a'+1,
            H2=H2*P+s2[i]-'a'+1;
        pair<ull,ull>H={H1,H2};
        int now1=0,now2=0;
        if(rtl.count(H))
            now1=rtl[H],
            now2=rtr[H];
        else
            now1=rtl[H]=++cnt,
            now2=rtr[H]=++cnt;
        for(int i=l-1;i>=0;i--)
        {
            if(!trie[now1][s1[i]-'a'])
                trie[now1][s1[i]-'a']=++cnt;
            now1=trie[now1][s1[i]-'a'];
        }
        for(int i=r+1;i<k;i++)
        {
            if(!trie[now2][s2[i]-'a'])
                trie[now2][s2[i]-'a']=++cnt;
            now2=trie[now2][s2[i]-'a'];
        }
        ano[now1].push_back(now2);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
            continue;
        int k=t1.size(),l=0,r=k-1;
        for(int i=0;i<k;i++)
            if(t1[i]!=t2[i])
            {
                l=i;
                break;
            }
        for(int i=k-1;i>=0;i--)
            if(t1[i]!=t2[i])
            {
                r=i;
                break;
            }
        ull H1=0,H2=0;
        for(int i=l;i<=r;i++)
            H1=H1*P+t1[i]-'a'+1,
            H2=H2*P+t2[i]-'a'+1;
        pair<ull,ull>H={H1,H2};
        int now1=0,now2=0;
        if(!rtl.count(H))
            continue;
        now1=rtl[H];
        now2=rtr[H];
        for(int i=l-1;i>=0;i--)
            if(trie[now1][t1[i]-'a'])
                now1=trie[now1][t1[i]-'a'];
            else
                break;
        for(int i=r+1;i<k;i++)
            if(trie[now2][t1[i]-'a'])
                now2=trie[now2][t1[i]-'a'];
            else
                break;
        qry[now1].push_back({now2,i});
    }
    for(auto[H,x]:rtr)
        dfs(x);
    for(auto[H,x]:rtl)
        solve(x);
    for(int i=1;i<=q;i++)
        cout<<Ans[i]<<"\n";
}