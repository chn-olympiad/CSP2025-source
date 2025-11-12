#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define OPEN freopen ("club.in", "r", stdin); freopen ("club.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);

constexpr int N = 2e5 + 5, L = 5e6 + 5;

using namespace std;

ll a[N][3];
vector <int> v[3];
int id;

void Main () {
    F (i, 0, 2) v[i].clear ();
    int n;
    cin >> n;
    F (i, 1, n) {
        F (j, 0, 2) cin >> a[i][j];
    }
    
    F (i, 1, n) {
        ll mx = 0LL, pos = 0;
        F (j, 0, 2)
            if (a[i][j] > mx) mx = a[i][j], pos = j;
        v[pos].push_back (i);
    }

    id = -1;

    F (i, 0, 2)
        if (v[i].size () > (n / 2)) {
            id = i;
            break;
        }
    ll res = 0LL;
    F (i, 0, 2) {
        for (auto j : v[i]) res += a[j][i];
    }
    if (id == -1) {
        
        cout << res << '\n';
        return ;
    } else {
        sort (v[id].begin (), v[id].end (), [] (int x, int y) {
            ll w1 = 0LL, w2 = 0LL;
            F (i, 0, 2)
                if (i != id) w1 = max (w1, a[x][i]), w2 = max (w2, a[x][i]);
            return w1 < w2;
        }) ;

        int cnt = v[id].size () - (n / 2);

        for (auto i : v[id]) {
            ll w = 0LL;
            F (j, 0, 2)
                if (j != id) w = max (w, a[i][j]);
            -- cnt;
            res += w - a[i][id];
            if (! cnt) break;
        }
    }
    cout << res << '\n';
}

int main () {
    int T;
    OPEN IOS
    cin >> T;
    while (T --> 0) Main ();
    return 0;
}