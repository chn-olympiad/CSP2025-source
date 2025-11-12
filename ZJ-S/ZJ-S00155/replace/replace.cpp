#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> hval;
constexpr int N=2e5+3,M=5e6+3;
constexpr int P1=998244353,P2=1e9+7,T1=1145141,T2=123419;
constexpr int Primes[]={101,151,227,347,521,787,1181,1777,2671,4007,6011,9029,13553,20333,30509,45763,68659,103001,154501,231779,347671,521519};
inline hval operator+(const hval &u,int x){return hval(((ll)u.first*T1+x)%P1,((ll)u.second*T2+x)%P2);}

int n,q,a[M],cnt;
int pw1[M],pw2[M],cmem[N];

template<typename T,size_t siz> struct Memory{
    T a[siz],*p;
    Memory(){p=a;}
    inline void alloc(T* &res,int m){res=p,p+=m+(m&1);}
};
Memory<int,50000000> memint;
Memory<ll,20000000> memll;
// unordered_map<ll,int> mp[2500];

struct HashTable{
    int P;
    int *val,*nxt,cnt,*head;
    ll *key;
    inline void alloc(int n){
        int i=0;
        while(Primes[i]<n*1.5)i++;
        P=Primes[i];
        memint.alloc(val,n);
        memint.alloc(nxt,n);
        memint.alloc(head,P);
        fill_n(head,P,-1);
        cnt=0;
        memll.alloc(key,n);
    }
    inline int get(ll x){
        for(int i=head[x%P];~i;i=nxt[i]){
            if(key[i]==x)return val[i];
        }
        return 0;
    }
    inline void inc(ll x){
        int id=x%P;
        for(int i=head[id];~i;i=nxt[i]){
            if(key[i]==x)return val[i]++,void();
        }
        int i=cnt++;
        nxt[i]=head[id];
        val[i]=1;
        key[i]=x;
        head[id]=i;
    }
}mp[2500];

struct String{
    int m;
    vector<int> s;
    vector<hval> h;
    inline void read(){
        static char str[M];
        scanf("%s",str+1),m=strlen(str+1),s.resize(m+1),h.resize(m+1);
        for(int i=1;i<=m;i++)s[i]=123+(int)str[i],h[i]=h[i-1]+s[i];
    }
    inline hval substr(int l,int r){
        return hval(
            (h[r].first-(ll)h[l-1].first*pw1[r-l+1]%P1+P1)%P1,
            (h[r].second-(ll)h[l-1].second*pw2[r-l+1]%P2+P2)%P2
        );
    }
}s1[N],s2[N],t1,t2;

inline ll calc(const hval &u,const hval &v,int len){
    int x=((ll)u.first*pw1[len]+v.first)%P1;
    int y=((ll)u.second*pw2[len]+v.second)%P2;
    return (ll)x*P2+y;
}

inline ll solve(){
    t1.read(),t2.read();
    if(t1.m!=t2.m)return 0;
    ll ans=0;
    int pl=1,pr=t1.m;
    while(t1.s[pl]==t2.s[pl])pl++;
    while(t1.s[pr]==t2.s[pr])pr--;
    for(int i=cnt;i;i--){
        int m=a[i];
        if(m<pr-pl+1)break;
        auto &f=mp[i];
        for(int r=max(m,pr),lim=min(t1.m,pl+m-1);r<=lim;r++){
            ll id=calc(t1.substr(r-m+1,r),t2.substr(r-m+1,r),m);
            // ans+=f.count(id)?f[id]:0;
            ans+=f.get(id);
        }
    }
    return ans;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=pw1[0]=pw2[0]=1;i<M;i++)pw1[i]=(ll)pw1[i-1]*T1%P1,pw2[i]=(ll)pw2[i-1]*T2%P2;
    for(int i=1;i<=n;i++)s1[i].read(),s2[i].read(),a[i]=s1[i].m;
    sort(a+1,a+1+n),cnt=unique(a+1,a+1+n)-a-1;
    static int xx[N];
    for(int i=1;i<=n;i++){
        if(s1[i].h.back()==s2[i].h.back())continue;
        int x=lower_bound(a+1,a+1+cnt,s1[i].m)-a;
        xx[i]=x;
        cmem[x]++;
    }
    for(int i=1;i<=cnt;i++)mp[i].alloc(cmem[i]);
    for(int i=1;i<=n;i++){
        if(s1[i].h.back()==s2[i].h.back())continue;
        int x=xx[i];
        // auto &f=mp[x];
        ll id=calc(s1[i].h.back(),s2[i].h.back(),a[x]);
        // f[id]++;
        mp[x].inc(id);
    }
    while(q--)printf("%lld\n",solve());
    return 0;
}