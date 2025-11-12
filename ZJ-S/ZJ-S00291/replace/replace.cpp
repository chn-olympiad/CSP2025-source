#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int SZ=1e7+10;

int n,q;
char pol[SZ+N*2<<1],*o;
char *S[N][2],*T[N][2];
int lens[N],lent[N][2];
pair<int,int> slr[N],tlr[N];
int ans[N];
int ch[SZ][26],tot;
bool ed[SZ];
int pss[N][2],pst[N][2];
int dfn[SZ],num,L[SZ],R[SZ];

int New() {
    tot++;
    assert(tot<SZ);
    for(int i=0;i<26;i++) ch[tot][i]=0;
    ed[tot]=0;
    return tot;
}

int ins(char *S,int len,bool rev=0) {
    int p=0;
    if(rev) {
        for(int i=len;i>=1;i--) {
            if(!ch[p][S[i]-'a']) ch[p][S[i]-'a']=New();
            p=ch[p][S[i]-'a'];
        }
    }
    else {
        for(int i=1;i<=len;i++) {
            if(!ch[p][S[i]-'a']) ch[p][S[i]-'a']=New();
            p=ch[p][S[i]-'a'];
        }
    }
    ed[p]=1;
    return p;
}

struct BIT{
    int t[N<<1];
    int n;

    int lowbit(int x) {
        return x&-x;
    }

    void init(int nn) {
        n=nn;
        for(int i=1;i<=n;i++) t[i]=0;
    }

    void change(int pos,int val) {
        for(;pos<=n;pos+=lowbit(pos)) t[pos]+=val;
    }

    int sum(int pos) {
        int res=0;
        for(;pos;pos-=lowbit(pos)) res+=t[pos];
        return res;
    }

    int query(int l,int r) {
        return sum(r)-sum(l-1);
    }
}bit;

void dfs(int u) {
    L[u]=num+1;
    if(ed[u]) dfn[u]=++num;
    for(int i=0;i<26;i++) if(ch[u][i]) dfs(ch[u][i]);
    R[u]=num;
}

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    o=pol;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) {
            S[i][j]=o;
            scanf("%s",S[i][j]+1);
            lens[i]=strlen(S[i][j]+1);
            o+=lens[i]+1;
        }
        int p=1,q=lens[i];
        while(p<=q) {
            if(S[i][0][q]==S[i][1][q]) q--;
            else if(S[i][0][p]==S[i][1][p]) p++;
            else break;
        }
        slr[i]={p,q};
    }
    for(int i=1;i<=q;i++) {
        for(int j=0;j<2;j++) {
            T[i][j]=o;
            scanf("%s",T[i][j]+1);
            lent[i][j]=strlen(T[i][j]+1);
            o+=lent[i][j]+1;
        }
        if(lent[i][0]!=lent[i][1]) tlr[i]={1,0};
        else {
            int p=1,q=lent[i][0];
            while(p<=q) {
                if(T[i][0][q]==T[i][1][q]) q--;
                else if(T[i][0][p]==T[i][1][p]) p++;
                else break;
            }
            tlr[i]={p,q};
        }
    }
    for(int i=0;i<2;i++) {
        tot=-1;
        New();
        for(int j=1;j<=n;j++) if(slr[j].first<=slr[j].second) pss[j][i]=ins(S[j][i]+slr[j].first-1,slr[j].second-slr[j].first+1);
        for(int j=1;j<=q;j++) if(tlr[j].first<=tlr[j].second) pst[j][i]=ins(T[j][i]+tlr[j].first-1,tlr[j].second-tlr[j].first+1);
    }
    vector<pair<pair<int,int>,int> > arr;
    for(int i=1;i<=n;i++) if(slr[i].first<=slr[i].second) arr.push_back({{pss[i][0],pss[i][1]},i});
    for(int i=1;i<=q;i++) if(tlr[i].first<=tlr[i].second) arr.push_back({{pst[i][0],pst[i][1]},-i});
    sort(arr.begin(),arr.end());
    int l=0;
    while(l<arr.size()) {
        int r=l;
        while(r+1<arr.size() && arr[l].first==arr[r+1].first) r++;
        static pair<int,int> lrs[N];
        static int sps[N],tps[N],tdfn[N];
        tot=-1;
        New();
        for(int i=l;i<=r;i++) {
            int u=arr[i].second;
            if(u>0) {
                sps[u]=ins(S[u][0],slr[u].first-1,1);
            }
            else {
                u*=-1;
                tps[u]=ins(T[u][0],tlr[u].first-1,1);
            }
        }
        num=0;
        dfs(0);
        bit.init(num);
        for(int i=l;i<=r;i++) {
            int u=arr[i].second;
            if(u>0) {
                lrs[u]={L[sps[u]],R[sps[u]]};
            }
            else {
                u*=-1;
                tdfn[u]=dfn[tps[u]];
            }
        }
        tot=-1;
        New();
        for(int i=l;i<=r;i++) {
            int u=arr[i].second;
            if(u>0) {
                sps[u]=ins(S[u][0]+slr[u].second,lens[u]-slr[u].second);
            }
            else {
                u*=-1;
                tps[u]=ins(T[u][0]+tlr[u].second,lent[u][0]-tlr[u].second);
            }
        }
        num=0;
        dfs(0);
        static vector<int> inss[N<<1],inst[N<<1],dels[N<<1];
        for(int i=1;i<=num+1;i++) inss[i].clear(),inst[i].clear(),dels[i].clear();
        for(int i=l;i<=r;i++) {
            int u=arr[i].second;
            if(u>0) {
                inss[L[sps[u]]].push_back(u);
                dels[R[sps[u]]+1].push_back(u);
            }
            else {
                u*=-1;
                inst[dfn[tps[u]]].push_back(u);
            }
        }
        for(int i=1;i<=num;i++) {
            for(int j:inss[i]) {
                bit.change(lrs[j].first,1);
                bit.change(lrs[j].second+1,-1);
            }
            for(int j:dels[i]) {
                bit.change(lrs[j].first,-1);
                bit.change(lrs[j].second+1,1);
            }
            for(int j:inst[i]) {
                ans[j]=bit.sum(tdfn[j]);
            }
        }
        l=r+1;
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
//16:41