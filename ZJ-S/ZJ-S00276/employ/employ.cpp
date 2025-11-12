#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define gc getchar

const int N = 500 + 5;
const int mod = 998244353;
const int INF = 1e18;

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

int n,m,a[N],b[N],p[N];

char s[N];

void SOLVE(){
    n=rd(),m=rd();
    cin>>(s+1);
    F(i,1,n){
        if(s[i]=='0'){
            b[i]=0;
        }else{
            b[i]=1;
        }
    }
    F(i,1,n){
        a[i]=rd();
    }
    int ans=0;
    F(i,1,n)p[i]=i;
    do{
        int cnt=0,x=0;
        F(i,1,n){
            if(b[i]==0){
                ++x;
            }else{
                if(a[p[i]]<=x){
                    ++x;
                }else{
                    ++cnt;
                }
            }
        }
        if(cnt>=m){
            ++ans;
        }
        // F(i,1,n){
        //     cerr<<p[i]<<' ';
        // }
        // cerr<<'\n';
    }while(next_permutation(p+1,p+n+1));
    printf("%lld\n",ans);
    return ;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T=1;
    while(T--){
        SOLVE();
    }
    return 0;
}