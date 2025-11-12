#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
// #define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define gc getchar

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int mod = 0;

int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=getchar()){
        if(c=='-')y=-1;
    }
    for(;isdigit(c);c=getchar()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

void cmx(int &a,int b){
    a=max(a,b);
}

void cmn(int &a,int b){
    a=min(a,b);
}

void add(int &a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

const ull base = 31;

int n,q;

string s1[N],s2[N],t1,t2;

vector<ull>hs1[N],hs2[N],hs,hsh;

ull pw[M];

int get(char c){
    return c-'a'+1;
}

vector<pii>t[M<<1];

void sub(){
    F(i,1,n){
        int p1=0,p2=0;
        int m=SZ(s1[i]);
        F(j,0,m-1){
            if(s1[i][j]=='b'){
                p1=j;
            }
            if(s2[i][j]=='b'){
                p2=j;
            }
        }
        int x=p1-p2+M-5;
        t[x].pb(mp(min(p1,p2),min(m-p1+1,m-p2+1)));
    }
    while(q--){
        cin>>t1>>t2;
        if(SZ(t1)!=SZ(t2)){
            puts("0");
            continue;
        }
        int m=SZ(t1);
        int p1=0,p2=0;
        F(i,0,m-1){
            if(t1[i]=='b'){
                p1=i;
            }else{
                if(t1[i]!='a'){
                    puts("0");
                    continue;
                }
            }
            if(t2[i]=='b'){
                p2=i;
            }else{
                if(t2[i]!='a'){
                    puts("0");
                    continue;
                }
            }
        }
        int x=p1-p2+M-5;
        int p=min(p1,p2),q=min(m-p1+1,m-p2+1);
        int ans=0;
        for(pii i:t[x]){
            if(i.fi<=p&&i.se<=q){
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
}

void SOLVE(){
    n=rd(),q=rd();
    pw[0]=1;
    F(i,1,M-5){
        pw[i]=pw[i-1]*base;
    }
    bool fl=1;
    F(i,1,n){
        cin>>s1[i]>>s2[i];
        int m=SZ(s1[i]);
        hs1[i].resize(m+1);
        hs2[i].resize(m+1);
        int cnta1=0,cntb1=0,cnta2=0,cntb2=0;
        F(j,1,m){
            hs1[i][j]=hs1[i][j-1]*base+get(s1[i][j-1]);
            hs2[i][j]=hs2[i][j-1]*base+get(s2[i][j-1]);
            if(s1[i][j-1]=='a'){
                ++cnta1;
            }
            if(s1[i][j-1]=='b'){
                ++cntb1;
            }
            if(s2[i][j-1]=='a'){
                ++cnta2;
            }
            if(s2[i][j-1]=='b'){
                ++cntb2;
            }
        }
        if(cnta1!=m-1||cntb1!=1||cnta2!=m-1||cntb2!=1){
            fl=0;
        }
    }
    if(fl&&q>=1e3){
        sub();
        return ;
    }
    while(q--){
        int ans=0;
        cin>>t1>>t2;
        if(SZ(t1)!=SZ(t2)){
            puts("0");
            continue;
        }
        int m=SZ(t1);
        int l=0,r=m-1;
        while(t1[l]==t2[l]){
            ++l;
        }
        while(t1[r]==t2[r]){
            r--;
        }
        ++l,++r;
        hs.resize(m+1),hsh.resize(m+1);
        F(i,1,m){
            hs[i]=hs[i-1]*base+get(t1[i-1]);
            hsh[i]=hsh[i-1]*base+get(t2[i-1]);
            // cerr<<hs[i]<<' ';
        }
        // cerr<<'\n';
        // cerr<<l<<' '<<r<<'\n';
        ull x=hs[r]-hs[l-1]*pw[r-l+1];
        // cerr<<l<<' '<<r<<' '<<x<<'\n';
        int len=r-l+1;
        F(i,1,n){
            F(j,1,SZ(s1[i])-len+1){
                int L=j,R=j+len-1;
                // cerr<<i<<' '<<L<<' '<<R<<'\n';
                if(hs1[i][R]-hs1[i][L-1]*pw[R-L+1]==x){
                    // cerr<<l<<' '<<r<<' '<<L<<' '<<R<<'!'<<'\n';
                    int ll=l-(L-1),rr=r+(SZ(s1[i])-R);
                    if(ll<=0||rr>m||hs1[i][SZ(s1[i])]!=hs[rr]-hs[ll-1]*pw[rr-ll+1]){
                        continue;
                    }
                    if(hs2[i][SZ(s2[i])]==hsh[rr]-hsh[ll-1]*pw[rr-ll+1]){
                        ++ans;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return ;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1;
    while(T--){
        SOLVE();
    }
    return 0;
}