#include<bits/stdc++.h>
#define TT 1000000007
#define LL long long
#define maxn 5000005
using namespace std;
int N,Q,cnt,tot,to[maxn],Ans[maxn],siz[maxn*2],num[maxn*2],dfn,T[maxn<<2];
char S1[maxn],S2[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
    return ret*f;
}
int root[maxn][2];
map<LL,int> mp;
struct QSQ{
    vector<int> to,ask,Qid;
    char ch[26];
}Trie[maxn*2];
void DFS(int x){
    num[x]=++dfn;
    siz[x]=1;
    for(int i=0;i<26;i++){
        if(Trie[x].ch[i]) DFS(Trie[x].ch[i]),siz[x]+=siz[Trie[x].ch[i]];
    }
}
void Update(int p,int pl,int pr,int L,int R,int v){
    // printf("%d %d %d\n",L,R,v);
    if(L<=pl&&pr<=R) {
        T[p]+=v; return;
    }
    int mid=pl+pr>>1;
    if(L<=mid) Update(p<<1,pl,mid,L,R,v);
    if(R> mid) Update(p<<1|1,mid+1,pr,L,R,v);
    return;
}
int Query(int p,int pl,int pr,int L){
    // printf("%d %d %d\n",pl,pr,L);
    int res=T[p];
    if(pl==pr) return res;
    int mid=pl+pr>>1;
    if(L<=mid) return res+Query(p<<1,pl,mid,L);
    else return res+Query(p<<1|1,mid+1,pr,L);
}
void dfs(int x){
    int sz=Trie[x].to.size();
    for(int i=0;i<sz;i++) {
        int y=Trie[x].to[i];
        Update(1,1,dfn,num[y],num[y]+siz[y]-1,1);
    }
    int sz2=Trie[x].ask.size();
    for(int i=0;i<sz2;i++){
        Ans[Trie[x].Qid[i]]=Query(1,1,dfn,num[Trie[x].ask[i]]);
    }
    for(int i=0;i<26;i++){
        if(Trie[x].ch[i]) dfs(Trie[x].ch[i]);
    }
    for(int i=0;i<sz;i++) {
        int y=Trie[x].to[i];
        Update(1,1,dfn,num[y],num[y]+siz[y]-1,-1);
    }
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    N=read(),Q=read();
    for(int tt=1;tt<=N;tt++){
        scanf("%s%s",S1,S2);
        int len=strlen(S1),hed=-1,til=len;
        for(int i=0;i<len;i++){
            if(S1[i]==S2[i])++hed;
            else break;
        }
        for(int i=len-1;i>=0;i--){
            if(S1[i]==S2[i])--til;
            else break;
        }
        if(hed+1==len)continue;
        else{
            LL hsh1=0,hsh2=0;
            for(int i=hed+1;i<til;i++){
                hsh1=(hsh1*17%TT+S1[i]-'a')%TT;
                hsh2=(hsh2*19%TT+S2[i]-'a')%TT;
            }
        //    printf("%lld\n",hsh1+hsh2);
            if(!mp[hsh2+hsh1*1145141]){
                ++cnt;mp[hsh2+hsh1*1145141]=cnt;
                root[cnt][0]=++tot;root[cnt][1]=++tot;
            }
            int now=root[mp[hsh2+hsh1*1145141]][0],nownow=root[mp[hsh2+hsh1*1145141]][1];
            for(int i=hed;i>=0;i--){
                if(!Trie[now].ch[S1[i]-'a']) Trie[now].ch[S1[i]-'a']=++tot;
                now=Trie[now].ch[S1[i]-'a'];
            }
            for(int i=til;i<len;i++){
                if(!Trie[nownow].ch[S1[i]-'a']) Trie[nownow].ch[S1[i]-'a']=++tot;
                nownow=Trie[nownow].ch[S1[i]-'a'];
            }
            Trie[now].to.push_back(nownow);
        }
    }
    for(int tt=1;tt<=Q;tt++){
        scanf("%s%s",S1,S2);
        int len=strlen(S1),hed=0,til=len-1;
        while(S1[hed]==S2[hed])++hed;
        while(S1[til]==S2[til])--til;
        LL hsh1=0,hsh2=0;
        for(int i=hed;i<=til;i++){
            hsh1=(hsh1*17%TT+S1[i]-'a')%TT;
            hsh2=(hsh2*19%TT+S2[i]-'a')%TT;
        }
                //    printf("%lld\n",hsh1+hsh2);

        if(!mp[hsh2+hsh1*1145141])continue;

        int now=root[mp[hsh2+hsh1*1145141]][0],nownow=root[mp[hsh2+hsh1*1145141]][1];
        for(int i=hed-1;i>=0;i--){
            if(!Trie[now].ch[S1[i]-'a']) break;
            now=Trie[now].ch[S1[i]-'a'];
        }
        for(int i=til+1;i<len;i++){
            if(!Trie[nownow].ch[S1[i]-'a']) break;
            nownow=Trie[nownow].ch[S1[i]-'a'];
        }
        Trie[now].ask.push_back(nownow),Trie[now].Qid.push_back(tt);
    }
    for(int i=1;i<=cnt;i++){
        // printf("%d %d\n",root[i][0],root[i][1]);
        DFS(root[i][1]);
    }
    for(int i=1;i<=cnt;i++){
        dfs(root[i][0]);
    }
    for(int i=1;i<=Q;i++) printf("%d\n",Ans[i]);
    // printf("%.4lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}