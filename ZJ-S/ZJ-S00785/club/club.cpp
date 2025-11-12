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
const ll N = 100005;
ll n,m;
ll a[N][3], o[N], b[N], p[N];
bool cmp(ll x,ll y){
    return b[x]<b[y];
}
void work(){
    ll i,j;
    read(n);
    fr(i,1,n)
        fr(j,0,2) read(a[i][j]);
    ll ans=0,s[3]; memset(s,0,sizeof(s));
    fr(i,1,n){
        ll mx = max(a[i][0],max(a[i][1],a[i][2]));
        ans += mx;
        fr(j,0,2){
            if (a[i][j]==mx){
                o[i] = j;
                s[j]++;
                break;
            }
        }
    }
    ll id = 0, el = 0;
    fr(j,0,2)
        if (s[j]>n/2) id = j, el = s[j]-n/2;
//    if (el>0) printf("!!!\n");
    fr(i,1,n){
        b[i] = inf;
        if (o[i]==id){
            fr(j,0,2)
                if (j!=id) Min(b[i],a[i][id]-a[i][j]);
        }
    }
    sort(b+1,b+1+n);
    fr(i,1,el) ans -= b[i];
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll qt; read(qt);
    while (qt--) work();
    return 0;
}
//g++ club.cpp -o a -Wall -O2 -std=c++11