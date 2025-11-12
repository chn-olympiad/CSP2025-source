#include <bits/stdc++.h>
using namespace std; bool _bg;
int n, a[100010][3];
void work(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int &j : a[i])cin >> j;
    int c[3]{};
    long long S = 0;
    vector<int> md[3];
    for (int i = 1; i <= n; ++i){
        vector<pair<int, int> > V;
        for (int j = 0; j < 3; ++j)
            V.emplace_back(a[i][j], j);
        sort(V.begin(), V.end(), greater<pair<int, int> >{});
        S += V[0].first;
        ++c[V[0].second];
        md[V[0].second].emplace_back(V[0].first - V[1].first);
    }
    for (auto &U : md)sort(U.begin(), U.end(), greater<int>{});
    while (max({c[0], c[1], c[2]}) > n / 2){
        auto &R = md[max_element(c, c + 3) - c];
        assert(!R.empty());
        S -= R.back(), R.pop_back(), --c[max_element(c, c + 3) - c];
    }
    cout << S << "\n";
}
bool _ed; int main(){
    double mmus = fabs(&_ed - &_bg) / 1024 / 1024;
    assert(mmus < 256); clog << mmus << "M" << endl;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)work();
    return 0;
}