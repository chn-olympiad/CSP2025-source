#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e5+5,L=5e6+5;
struct ACAM{
    int trie[L][26],len[L],pnd=1;
    int Insert(string s){
        int p=1;
        for(char c:s){
            int ch=c-'a';
            if(!trie[p][ch]) len[trie[p][ch]=++pnd]=len[p]+1;
            p=trie[p][ch];
        }
        return p;
    }
    int fail[L],dfn[L],siz[L],idx[L],son[L],fir[L],pdfn;
    vector<int> G[L];
    void DFS1(int u){
        siz[u]=1;
        for(int v:G[u]){
            DFS1(v),siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
    void DFS2(int u,int firu){
        fir[u]=firu,idx[dfn[u]=++pdfn]=u;
        if(son[u]) DFS2(son[u],firu);
        for(int v:G[u]) if(v!=son[u]) DFS2(v,v);
    }
    void Build(){
        for(int c=0;c<26;++c) trie[0][c]=1;
        queue<int> que;
        que.push(1);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int c=0;c<26;++c){
                int v=trie[u][c];
                if(v) fail[v]=trie[fail[u]][c],que.push(v);
                else trie[u][c]=trie[fail[u]][c];
            }
        }
        for(int i=2;i<=pnd;++i) G[fail[i]].emplace_back(i);
        DFS1(1),DFS2(1,1);
    }
    int Find(int p,int l){
        if(l<=0) return 1;
        while(len[fail[fir[p]]]>=l) p=fail[fir[p]];
        int dl=dfn[fir[p]],dr=dfn[p];
        while(dl<dr){
            int mid=(dl+dr)>>1;
            if(len[idx[mid]]>=l) dr=mid;
            else dl=mid+1;
        }
        return fail[idx[dl]];
    }
}M1,M2;
namespace DS{
    int lim,tr[L];
    void Add(int x,int v){
        for(;x<=lim;x+=x&-x) tr[x]+=v;
    }
    int Sum(int x){
        int res=0;
        for(;x;x-=x&-x) res+=tr[x];
        return res;
    }
}
int n,q,id1[N],id2[N];
i64 ans[N];
vector<tuple<int,int,int>> Q1[L],Q2[L];
void Work(){
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        string s1,s2;
        cin>>s1>>s2;
        id1[i]=M1.Insert(s1);
        id2[i]=M2.Insert(s2);
    }
    M1.Build(),M2.Build();
    for(int i=1;i<=n;++i){
        int l1=M1.dfn[id1[i]],r1=l1+M1.siz[id1[i]]-1;
        int l2=M2.dfn[id2[i]],r2=l2+M2.siz[id2[i]]-1;
        Q1[l1].emplace_back(l2,r2,1);
        Q1[r1+1].emplace_back(l2,r2,-1);
        // printf("%d %d\n",id1[i],id2[i]);
    }
    for(int t=1;t<=q;++t){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) continue;
        int len=t1.size(),l=len,r=0;
        for(int i=0;i<len;++i)
            if(t1[i]!=t2[i]) l=min(l,i),r=max(r,i);
        // printf("%d %d\n",l,r);
        int p1=1,p2=1;
        for(int i=0;i<len;++i){
            p1=M1.trie[p1][t1[i]-'a'];
            p2=M2.trie[p2][t2[i]-'a'];
            if(i>=r&&M1.len[p1]>=i-l+1&&M2.len[p2]>=i-l+1){
                int q1=M1.Find(p1,i-l+1),q2=M2.Find(p2,i-l+1);
                // printf("%d %d %d %d\n",p1,p2,q1,q2);
                Q2[M1.dfn[p1]].emplace_back(M2.dfn[p2],t,1);
                Q2[M1.dfn[p1]].emplace_back(M2.dfn[q2],t,-1);
                Q2[M1.dfn[q1]].emplace_back(M2.dfn[p2],t,-1);
                Q2[M1.dfn[q1]].emplace_back(M2.dfn[q2],t,1);
            }
        }
    }
    DS::lim=M2.pnd;
    for(int i=1;i<=M1.pnd;++i){
        for(auto [l,r,v]:Q1[i]){
            // printf("%d %d %d\n",l,r,v);
            DS::Add(l,v),DS::Add(r+1,-v);
        }
        for(auto [x,id,v]:Q2[i]){
            // printf("%d %d %d\n",x,id,v);
            ans[id]+=v*DS::Sum(x);
        }
    }
    for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}