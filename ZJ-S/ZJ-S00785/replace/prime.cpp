#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
#define Max(x,y) x = max(x,y)
#define Min(x,y) x = min(x,y)
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch!=EOF){
        if (ch=='-') w = -1;
        ch = getchar();
    }
    while (isdigit(ch) && ch!=EOF){
        n = n*10 + ch-'0';
        ch = getchar();
    }
    n *= w;
}
const ll N = 200005, S = 5000005;
struct Suiji{
    Suiji(){ srand((unsigned)time(NULL)); }
    #define R ((ll)rand())
    ll M(ll l,ll r){
        return ( (R*R*R+R*R+R)%(r-l+1) + (r-l+1) ) % (r-l+1) + l;
    }
}suiji;
bool check(ll x){
    ll i;
    for (i=2; i*i<=x; i++)
        if (x%i==0) return false;
    return true;
}
int main(){
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    while (1){
        ll x = suiji.M(5e8,1e9);
        if (check(x)){
            printf("%lld\n",x);
            return 0;
        }
    }
    return 0;
}
//g++ prime.cpp -o p -Wall -O2 -std=c++11