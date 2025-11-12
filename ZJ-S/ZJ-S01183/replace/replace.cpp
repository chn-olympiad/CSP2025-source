#include<bits/stdc++.h>
using namespace std;

// #define int ll
#define file(jzc) freopen(#jzc".in","r",stdin),freopen(#jzc".out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound
#define UB upper_bound
#define mkp make_pair
#define all(a) (a).begin(),(a).end()

using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using vi=vector<int>;
using vvi=vector<vi>;

template<typename T1,typename T2>
void chkmin(T1&x,const T2&y){if(y<x)x=y;}
template<typename T1,typename T2>
void chkmax(T1&x,const T2&y){if(x<y)x=y;}

constexpr int mod1=1010100011,mod2=1010000011;

struct JZC{
    int x,y;
    JZC(int x=0,int y=0):x(x),y(y){}
    JZC operator*(const JZC&a)const{return{(ll)x*a.x%mod1,(ll)y*a.y%mod2};}
    JZC operator+(const JZC&a)const{return{(x+a.x)%mod1,(y+a.y)%mod2};}
    JZC operator-(const JZC&a)const{return{(x-a.x+mod1)%mod1,(y-a.y+mod2)%mod2};}
    bool operator<(const JZC&a)const{return x!=a.x?x<a.x:y<a.y;}
};

const JZC base{1231231,2342381};

JZC gethash(const string&s){
    JZC res{};
    for(char c:s)res=res*base+JZC(c,c);
    return res;
}

struct{
    int n,jzc;
    int t[5000500],tt[5000500];
    void clear(){++jzc;}
    void add(int x,int v){for(;x<=n;x+=x&-x)tt[x]==jzc?(t[x]+=v):(t[x]=v,tt[x]=jzc);}
    int ask(int x){int a=0;for(;x;x&=x-1)tt[x]==jzc&&(a+=t[x]);return a;}
}bit;

int n,m;
string s1[200200],s2[200200];
string ss1[200200],ss2[200200];
map<pair<JZC,JZC>,pair<vi,vi>>mp;

pii getjzcjzc(const string&a,const string&b){
    int l=INT_MAX,r=0;
    for(int i=0;i<a.size();i++)if(a[i]!=b[i])chkmin(l,i),chkmax(r,i);
    return mkp(l,r);
}

struct{
    int t[2500250][26];
    int cntn;
    void clear(){
        for(int i=1;i<=cntn;i++)fill(t[i],t[i]+26,0);
        cntn=1;
    }
    int insert(const string&s){
        int nw=1;
        for(char c:s){
            if(!t[nw][c-'a'])t[nw][c-'a']=++cntn;
            nw=t[nw][c-'a'];
        }
        return nw;
    }
    int getpos(const string&s){
        int nw=1;
        for(char c:s){
            if(!t[nw][c-'a'])return nw;
            nw=t[nw][c-'a'];
        }
        return nw;
    }
}t1,t2;

int siz[2500250],dfn[2500250],cdfn;
vector<pii>q[2500250];
int ans[200200];

void dfs1(int u){
    siz[u]=1,dfn[u]=++cdfn;
    for(int i=0;i<26;i++)if(t1.t[u][i])dfs1(t1.t[u][i]),siz[u]+=siz[t1.t[u][i]];
}
void dfs2(int u){
    for(auto[x,y]:q[u])if(!y)bit.add(dfn[x],1),bit.add(dfn[x]+siz[x],-1);
    for(auto[x,y]:q[u])if(y)ans[y]=bit.ask(dfn[x]);
    for(int i=0;i<26;i++)if(t2.t[u][i])dfs2(t2.t[u][i]);
    for(auto[x,y]:q[u])if(!y)bit.add(dfn[x]+siz[x],1),bit.add(dfn[x],-1);
}

void solve(){
    bit.jzc=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string jzc,czj;
        cin>>jzc>>czj;
        if(jzc==czj)continue;
        auto[l,r]=getjzcjzc(jzc,czj);
        mp[mkp(gethash(jzc.substr(l,r-l+1)),gethash(czj.substr(l,r-l+1)))].fi.pb(i);
        s1[i]=jzc.substr(0,l),reverse(all(s1[i]));
        s2[i]=jzc.substr(r+1);
    }
    for(int i=1;i<=m;i++){
        string jzc,czj;
        cin>>jzc>>czj;
        if(jzc.size()!=czj.size())continue;
        auto[l,r]=getjzcjzc(jzc,czj);
        mp[mkp(gethash(jzc.substr(l,r-l+1)),gethash(czj.substr(l,r-l+1)))].se.pb(i);
        ss1[i]=jzc.substr(0,l),reverse(all(ss1[i]));
        ss2[i]=jzc.substr(r+1);
    }
    for(auto[_,dfjkjfd]:mp){
        const auto&[v1,v2]=dfjkjfd;
        if(!v1.size()||!v2.size())continue;
        for(int i=1;i<=t2.cntn;i++)q[i].clear();
        t1.clear(),t2.clear(),bit.clear();
        for(int i:v1)q[t2.insert(s2[i])].eb(t1.insert(s1[i]),0);
        for(int i:v2)q[t2.getpos(ss2[i])].eb(t1.getpos(ss1[i]),i);
        // for(int i:v1)cout<<i<<' ';cout<<"--- ";
        // for(int i:v2)cout<<i<<' ';cout<<'\n';
        bit.n=t1.cntn;
        cdfn=0,dfs1(1),dfs2(1);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
}

signed main(){
    file(replace);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
}

/*
much more difficult than T4

17:08 pass pretests
*/