#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e6 + 10;
int n, a[N][5];
vector<int>e[5];
void ___(){
    int sum = 0;
    e[1].clear(), e[2].clear(), e[3].clear();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        int ma = max({a[i][1], a[i][2], a[i][3]});
        if(ma == a[i][1])e[1].emplace_back(i), sum += a[i][1];
        else if(ma == a[i][2])e[2].emplace_back(i), sum += a[i][2];
        else if(ma == a[i][3])e[3].emplace_back(i), sum += a[i][3];
    }
    int o = 0, o1, o2;
    if(e[1].size() > n / 2)o = 1, o1 = 2, o2 = 3;
    if(e[2].size() > n / 2)o = 2, o1 = 1, o2 = 3;
    if(e[3].size() > n / 2)o = 3, o1 = 1, o2 = 2;
    if(!o)return cout << sum << endl, void();
    sort(e[o].begin(), e[o].end(), [&](int&i, int&j){
        return (a[i][o] - max(a[i][o1], a[i][o2])) < (a[j][o] - max(a[j][o1], a[j][o2]));
    });
    // cout << sum << endl;
    for(int k = 0, i; k <= e[o].size() - (n / 2) - 1; k++)
        i = e[o][k], sum -= a[i][o] - max(a[i][o1], a[i][o2]);
    cout<< sum << endl;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)___();
    return 0;
}