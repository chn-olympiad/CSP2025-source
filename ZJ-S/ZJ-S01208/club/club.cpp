#include<bits/stdc++.h>
using namespace std; 

namespace Main {

#define fir first
#define sec second
#define ld long double
#define all(x) begin(x), end(x) 
#define rep(i, l, r) for(int i(l), END##i(r); i <= END##i; ++ i) 
#define per(i, r, l) for(int i(r), END##i(l); i >= END##i; -- i) 

template<class T>
inline void cmax(T& x, const T& y) { x = max(x, y); }
template<class T>
inline void cmin(T& x, const T& y) { x = min(x, y); }

const int N = 1e5 + 10; 

int n, ans; 
pair<int, int> a[N][3]; 
vector<int>vec[3]; 

void ERoRain() {
    ans = 0; 
    rep(t, 0, 2) 
        vec[t].clear(); 
    scanf ("%d", &n); 
    rep(i, 1, n) {
        scanf ("%d%d%d", &a[i][0].fir, &a[i][1].fir, &a[i][2].fir); 
        rep(t, 0, 2) a[i][t].sec = t; 
        sort(a[i], a[i] + 3); 
        ans += a[i][2].fir; 
        vec[a[i][2].sec].emplace_back(a[i][2].fir - max(a[i][0].fir, a[i][1].fir)); 
    } 
    int t = 0; 
    rep(i, 1, 2) 
        if (vec[i].size() > vec[t].size()) 
            t = i; 
    sort(all(vec[t])); 
    int lim = n >> 1; 
    rep(i, 0, ((int)(vec[t].size()) - lim) - 1) 
        ans -= vec[t][i]; 
    printf ("%d\n", ans); 
}

signed main() {
    ld start_time = clock(); 
    int T; scanf ("%d", &T); 
    while (T --) ERoRain(); 
    fprintf (stderr, "Time : %Lf\n", (clock() - start_time) / CLOCKS_PER_SEC); 
    return 0; 
}

} signed main() {
    freopen("club.in", "r", stdin); 
    freopen("club.out", "w", stdout); 
    Main::main(); 
    return 0; 
}