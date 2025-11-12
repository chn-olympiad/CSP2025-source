#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
#define pb push_back
#define For(i, s, e) for(int i = (s); i <= (e); ++i)
#define ifor(i, s, e) for(int i = (s); i >= (e); --i)
inline ll read() {
    ll x(0); bool f(0); char ch = getchar();
    while(!isdigit(ch)) f = ch == '-', ch = getchar();
    while(isdigit(ch)) x = x * 10 + (ch^48), ch = getchar();
    return f ? -x : x;
}
inline void wt(ll x, bool md=1) {
    if(x < 0) putchar('-'), x = -x;
    short stack[64], top(0);
    do stack[++ top] = x % 10, x /= 10; while(x);
    while(top) putchar(stack[top --] | 48);
    md ? putchar('\n') : putchar(' ');
}
vector < int > stk[4];
struct node{int fi, se;}a[N][4];
int n;
void work() {
    ll ans(0);
    n = read();
    For(i, 1, n) {
        For(j, 1, 3) a[i][j] = {read(), j};
        sort(a[i] + 1, a[i] + 4, [](const node &x, const node &y){return x.fi > y.fi;});
        stk[a[i][1].se].pb(a[i][1].fi - a[i][2].fi); // mind
        ans += a[i][1].fi;
        // printf("cur = %d\n", a[i][1].fi);
    }
    // wt(ans);
    For(i, 1, 3) {
        sort(stk[i].begin(), stk[i].end(), [](const int &x, const int &y){return x > y;});
        while((int)stk[i].size() > n / 2) ans -= stk[i].back(), stk[i].pop_back();
    }
    wt(ans);
}
void clear() {For(i, 1, 3) stk[i].clear();}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int r = read(); r--;) work(), clear();
    return 0;
}