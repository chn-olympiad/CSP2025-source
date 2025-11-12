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

const int N = 1e5 + 5;
const int mod = 0;
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

struct node{
    int a,b,c;
}a[N];

int n,ans;

vector<int>b[3];

vector<int>vec;

void SOLVE(){
    n=rd();
    F(i,0,2){
        b[i].clear();
    }
    ans=0;
    vec.clear();
    F(i,1,n){
        a[i].a=rd(),a[i].b=rd(),a[i].c=rd();
        if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
            b[0].pb(i);
        }else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
            b[1].pb(i);
        }else{
            b[2].pb(i);
        }
        ans+=max(a[i].a,max(a[i].b,a[i].c));
    }
    if(SZ(b[1])>=n/2){
        swap(b[0],b[1]);
        F(i,1,n){
            swap(a[i].a,a[i].b);
        }
    }else if(SZ(b[2])>=n/2){
        swap(b[0],b[2]);
        F(i,1,n){
            swap(a[i].a,a[i].c);
        }
    }
    int x=SZ(b[0])-n/2;
    if(x<=0){
        printf("%lld\n",ans);
        return ;
    }
    for(int i:b[0]){
        vec.pb(a[i].a-max(a[i].b,a[i].c));
    }
    sort(vec.begin(),vec.end());
    F(i,0,x-1){
        ans-=vec[i];
    }
    printf("%lld\n",ans);
    return ;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=rd();
    while(T--){
        SOLVE();
    }
    return 0;
}