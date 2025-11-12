#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

const int N = 286;
pair<ll,ll> a[N];
ll s[N][N], pos;

inline bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    ll n,m;
    cin >> n >> m;
    for(ll i = 1; i <= n * m; i ++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    stable_sort(a + 1, a + n*m + 1,cmp);
    for(ll j = 1; j <= m; j++) {
        if(j & 1) {
            for(ll i = 1; i <= n; i++) {
                s[i][j] = a[++pos].second;
            }
        } else {
            for(ll i = n; i >= 1; i--) {
                s[i][j] = a[++pos].second;
            }
        }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
        	//cerr << s[i][j] << " ";
            if(s[i][j] == 1) {
                cout << j << " " << i;
                return 0;
            }
        }
        //cerr << endl;
    }

    return 0;
}
