#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,L=2.5e6+5;
int n,q;
struct trie{
    int tot,fail[L],tr[L][26];
    bool ed[L];
    int ist(char *str){
        int u=0,len=strlen(str);
        for(int i=0;i<len;i++){
            int ch=str[i]-'a';
            if(!tr[u][ch])tr[u][ch]=++tot;
            u=tr[u][ch];
        }
        ed[u]=1;
        return u;
    }
    int dfn[L],sz[L],h[L],nxt[L],to[L],cnt,dfntot;
    void addedge(int x,int y){
        nxt[++cnt]=h[x];to[cnt]=y;h[x]=cnt;
    }
    void dfs(int x){
        dfn[x]=++dfntot;
        sz[x]=1;
        for(int i=h[x];i;i=nxt[i])
            dfs(to[i]),sz[x]+=sz[to[i]];
    }
    void build(){
        queue<int>q;
        for(int i=0;i<26;i++)
            if(tr[0][i])q.push(tr[0][i]);
        while(!q.empty()){
            int x=q.front();q.pop();
            ed[x]|=ed[fail[x]];
            for(int i=0;i<26;i++)
                if(tr[x][i])fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
                else tr[x][i]=tr[fail[x]][i];
        }
        for(int i=1;i<=tot;i++)
            addedge(fail[i],i);
        dfs(0);
    }
    bool chk(int pa,int x){
        return dfn[pa]<=dfn[x]&&dfn[x]<=dfn[pa]+sz[pa]-1;
    }
}t1,t2;
char s[L],t[L];
int a[N],b[N],len[N];
ll ans[N];
struct node{
    int id,v,x,y,z;
    // node(int Id=0,int V=0,int X=0,int Y=0,int Z=0){
    //     id=Id;v=V;x=X;y=Y;z=Z;
    // }
    bool operator<(const node &x)const{
        if(z==x.z)return id<x.id;
        return z<x.z;
    }
}val[N*4+L];
int tot;
int getlcp(int m){
    for(int i=0;i<m;i++)
        if(s[i]!=t[i])return i;
    return m;
}
int getlcs(int m){
    for(int i=m-1;i>=0;i--)
        if(s[i]!=t[i])return m-i-1;
    return m;
}
int c[L],tim[L],Tim;
void clear(){++Tim;}
void add(int x,int v){
    assert(x);
    for(;x<=t2.dfntot+1;x+=x&-x){
        if(tim[x]!=Tim)tim[x]=Tim,c[x]=0;
        c[x]+=v;
    }
}
int qry(int x){
    int res=0;
    for(;x;x-=x&-x){
        if(tim[x]!=Tim)tim[x]=Tim,c[x]=0;
        res+=c[x];
    }
    return res;
}
bool chkmn(node a,node b){
    if(a.x==b.x)return a.id<b.id;
    return a.x<b.x;
}
node tmp[N*4+L];
void solve(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    clear();
    int m=0;
    for(int i=l,j=mid+1;i<=mid||j<=r;){
        if((j>r)||(i<=mid&&chkmn(val[i],val[j]))){
            tmp[++m]=val[i];
            auto [id,v,x,y,z]=val[i];
            if(!id)add(y,v);
            // else ans[id]+=qry(y);
            ++i;
        }else{
            tmp[++m]=val[j];
            auto [id,v,x,y,z]=val[j];
            if(id)ans[id]+=qry(y);
            // if(!id)add(y,v);
            // else ans[id]+=qry(y);
            ++j;
        }
    }
    for(int i=l;i<=r;i++)val[i]=tmp[i-l+1];
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s,t);
        a[i]=t1.ist(s);
        b[i]=t2.ist(t);
        len[i]=strlen(s);
    }
    t1.build();
    t2.build();
    for(int i=1;i<=n;i++){
        int x=t1.dfn[a[i]],szx=t1.sz[a[i]],y=t2.dfn[b[i]],szy=t2.sz[b[i]],z=-len[i];
        assert(y>0);assert(y+szy>0);
        val[++tot]={0,1,x,y,z};
        val[++tot]={0,1,x+szx,y+szy,z};
        val[++tot]={0,-1,x+szx,y,z};
        val[++tot]={0,-1,x,y+szy,z};
    }
    for(int T=1;T<=q;T++){
        scanf("%s%s",s,t);
        int lens=strlen(s),lent=strlen(t);
        if(lens!=lent){
            ans[T]=0;
            continue;
        }
        int m=lens;
        int lcp=getlcp(m),lcs=getlcs(m);
        int u=0,v=0;
        for(int i=0;i<m;i++){
            u=t1.tr[u][s[i]-'a'];
            v=t2.tr[v][t[i]-'a'];
            if(m-i-1<=lcs)
                val[++tot]={T,0,t1.dfn[u],t2.dfn[v],lcp-i-1};
        }
    }
    sort(val+1,val+1+tot);
    solve(1,tot);
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}