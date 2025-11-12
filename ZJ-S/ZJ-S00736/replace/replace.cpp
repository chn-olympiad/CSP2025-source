#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int INF=2.5e6+5;
const int INFN=5e5+5;
struct AAA {int x,y,z;};

int n,q;
long long ans[INFN];
struct ACAM{
    vector <int> e[INF];
    int trie[INF][26],rt,fa[INF],tot,id[INF],len[INF],sz[INF];
    vector <int> pre[INF];
    vector <AAA> L[INF];
    int dfn[INF],dpre[INF],dep[INF],fath[INF][23];
    queue <int> q;
    void ins(string s1,int p) {
        int x=rt,len4=s1.size();
        for (int w=0;w<len4;w++) {
            int c=s1[w]-'a';
            if (!trie[x][c]) trie[x][c]=++tot;
            x=trie[x][c];len[x]=w+1;
        }
        id[p]=x;pre[x].pb(p);
    }
    void init() {
        for (int i=0;i<26;i++)
            if (trie[1][i]) fa[trie[1][i]]=1,q.push(trie[1][i]);
            else trie[1][i]=1;
        while (q.size()) {
            int x=q.front();q.pop();
            for (int i=0;i<26;i++)
                if (trie[x][i]) 
                    fa[trie[x][i]]=trie[fa[x]][i],q.push(trie[x][i]);
                else trie[x][i]=trie[fa[x]][i];
        }
        for (int i=2;i<=tot;i++)
            e[fa[i]].pb(i);
    }
    void DFS(int x) {
        dfn[++dfn[0]]=x;dpre[x]=dfn[0];sz[x]=1;fath[x][0]=fa[x];
        for (int w=1;w<=__lg(dep[x]);w++) fath[x][w]=fath[fath[x][w-1]][w-1];
        for (int v:e[x]) dep[v]=dep[x]+1,DFS(v),sz[x]+=sz[v];
    }
    int Lo(int x,int li) {
        for (int u=__lg(dep[x]);u>=0;u--)
            if (len[fath[x][u]]>=li) x=fath[x][u];
        return fath[x][0];
    }
}T1,T2;
struct BIT{
    long long tree[INF];
    void add3(int l,int y) {for (int i=l;i<=2.5e6;i+=i&-i) tree[i]+=y;}
    void add(int l,int r,int y) {add3(l,y);add3(r+1,-y);}
    long long query(int l) {long long sum3=0;for (int i=l;i;i-=i&-i) sum3+=tree[i];return sum3;}
}T3,T4;
void DFS(int x) {
    for (int yy:T1.pre[x]) 
        T3.add(T2.dpre[T2.id[yy]],T2.dpre[T2.id[yy]]+T2.sz[T2.id[yy]]-1,1);
    for (auto yy:T1.L[x]) 
        ans[yy.z]+=T3.query(T2.dpre[yy.x])-T3.query(T2.dpre[yy.y]);
    for (int v:T1.e[x])
        DFS(v);
    for (int yy:T1.pre[x]) 
        T3.add(T2.dpre[T2.id[yy]],T2.dpre[T2.id[yy]]+T2.sz[T2.id[yy]]-1,-1);
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>q;T1.rt=T1.tot=1;T2.rt=T2.tot=1;
    int sum1=0,sum2=0;
    for (int i=1;i<=n;i++) {
        string s1,s2;
        cin>>s1>>s2;
        sum1+=s1.size()+s2.size();
        T1.ins(s1,i);T2.ins(s2,i);
    }
    T1.init();T2.init();
    T2.DFS(1);
    for (int I=1;I<=q;I++) {
        string t1,t2;
        cin>>t1>>t2;
        if (t1.size()!=t2.size()) continue;
        sum2+=t1.size()+t2.size();
        int len=t1.size(),rt1=1,rt2=1,L=0,R=0;
        for (int i=0;i<len;i++)
            if (t1[i]!=t2[i]) R=i;
        for (int i=len-1;i>=0;i--)
            if (t1[i]!=t2[i]) L=i;
        for (int i=0;i<len;i++) {
            int c1=t1[i]-'a',c2=t2[i]-'a';
            rt1=T1.trie[rt1][c1];
            rt2=T2.trie[rt2][c2];
            if (i<R) continue;
            if (T2.len[rt2]<i-L+1) continue;
            if (rt1!=1 && rt2!=1) 
                T1.L[rt1].pb({rt2,T2.Lo(rt2,i-L+1),I});
        }
    }
    // cerr<<sum1<<" "<<sum2<<" qwq?\n";
    DFS(1);
    for (int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}