#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
const int N=2e5+5,M=5e6+5;
int q[M],hd,tl;
struct dat{
    int l,r;
};
// int cntt;
struct AC{
    int son[M][26],tot,ct;
    int st[M],ed[M],len[M],f[M];
    int nex[M];
    vector<int> e[M];
    vector<dat> p[M];
    int ins(string &s){
        int now=0;
        for(auto c:s){
            if(!son[now][c-'a']) son[now][c-'a']=++tot,len[tot]=len[now]+1;
            now=son[now][c-'a'];
        }
        return now;
    }
    void dfs(int u){
        st[u]=++ct;
        for(auto v:e[u])
            dfs(v);
        ed[u]=ct;
    }
    void dfs2(int u){
        if(p[u].size()) nex[u]=u;
        for(auto v:e[u])
            nex[v]=nex[u],dfs2(v);
    }
    void build(){
        hd=1,tl=0;
        for(int i=0;i<26;++i)
            if(son[0][i]) q[++tl]=son[0][i];
        while(hd<=tl){
            int u=q[hd++];
            e[f[u]].push_back(u);
            // db("%d f %d\n",u,f[u]);
            for(int i=0;i<26;++i)
                if(son[u][i]){
                    f[son[u][i]]=son[f[u]][i],q[++tl]=son[u][i];
                }else son[u][i]=son[f[u]][i];
        }
        dfs(0);
        // db("---\n");
    }
    int ask(int u,int c,int l){
        // db("ask %d %d %d\n",u,c,l);
        int ans=0;
        for(u=nex[u];u&&len[u]>=l;u=nex[f[u]]){
            // db("%d:\n",u);
            // ++cntt;
            for(auto t:p[u]) ans+=(t.l<=c&&c<=t.r);//,++cntt;//,db("%d:%d %d\n",u,t.l,t.r);
            // db("--\n");
        }
        return ans;
    }
}p1,p2;
struct oper{
    int len,l,r,x,y,id;
}t[N<<1];
int ct;
struct ide{
    int id1,id2;
}id[N];
int n,m;
int ans[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    string s1,s2;
    for(int i=1;i<=n;++i){
        cin>>s1>>s2;
        id[i]={p1.ins(s1),p2.ins(s2)};
        t[i].len=s1.size();
        // db("%d %d>>\n",id[i].id1,id[i].id2);
    }
    p1.build(),p2.build();
    ct=n;
    for(int i=1;i<=n;++i){
        t[i].l=p1.st[id[i].id1],t[i].r=p1.ed[id[i].id1];
        t[i].x=p2.st[id[i].id2],t[i].y=p2.ed[id[i].id2];
        p1.p[id[i].id1].push_back({t[i].x,t[i].y});
        // db("%d:l %d to %d,r %d to %d\n",i,t[i].l,t[i].r,t[i].x,t[i].y);
    }
    p1.dfs2(0);
    for(int i=1;i<=m;++i){
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            printf("0\n");
            continue;
        }
        int tl,tr,len=s1.size(),ans=0;
        for(int i=0;i<len;++i)
            if(s1[i]!=s2[i]){
                tl=i;
                break;
            }
        for(int i=len-1;i>=0;--i)
            if(s1[i]!=s2[i]){
                tr=i;
                break;
            }
        // db("tl %d,tr %d\n",tl,tr);
        int pl=0,pr=0;
        for(int i=0;i<tr;++i){
            pl=p1.son[pl][s1[i]-'a'];
            pr=p2.son[pr][s2[i]-'a'];
        }
        for(int i=tr;i<len;++i){
            pl=p1.son[pl][s1[i]-'a'];
            pr=p2.son[pr][s2[i]-'a'];
            // db("%d:pl %d,pr %d\n",i,pl,pr);
            ans+=p1.ask(pl,p2.st[pr],i-tl+1);
        }
        printf("%d\n",ans);
    }
    // db("%d\n",cntt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}