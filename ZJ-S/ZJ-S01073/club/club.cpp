// 回来修改！

#include <bits/stdc++.h>

#define N 100005

using namespace std;

typedef long long ll;

// 变量定义
ll t;
ll n;
ll ans;
ll total_ans;

string tab = "";

ll haved[5]; // 已经有了的人数
ll pointer[N]; // 人取到了第几大的权值
ll a_to_b[N]; // 人 -> 俱乐部（0表示没有选择）
set<ll> b_to_a[N]; // 俱乐部 -> 人（0表示没有选择）
ll a[N][5];

struct choice {
    ll to;
    ll value;
    bool operator < (const choice other) const {
        return value < other.value;
    }
    bool operator > (const choice other) const {
        return value > other.value;
    }
};
vector<choice> choices[N];

// bool solve(ll now) {
//     // debug
//     cout << tab << "solve(" << now << ")" << endl;
//     string old_tab = tab;
//     tab += "  ";

//     if (!a_to_b[now]) {
//         cout << tab << "**NEW**" << endl;
//         // 没选过，都选择一遍
//         for (auto i : choices[now]) {
//             cout << tab << "Trying " << i.to << " " << b_to_a[i.to] << endl;
//             if (b_to_a[i.to].size() == n / 2) {
//                 // 这里人满了
//                 for (auto j : b_to_a[i.to]) {
//                     if (solve(b_to_a[i.to])) {
//                         // 办不到，舍弃
//                         continue;
//                     }
//                     b_to_a[i.to].push(now);
//                     a_to_b[now] = i.to;
//                     cout << tab << "ans: " << ans << " -> ";
//                     anssolve(ll now) {
//     // debug
//     cout << tab << "solve(" << now << ")" << endl;
//     string old_tab = tab;
//     tab += "  ";

//     if (!a_to_b[now]) {
//         cout << tab << "**NEW**" << endl;
//         // 没选过，都选择一遍
//         for (auto i : choices[now]) {
//             cout << tab << "Trying " << i.to << " " << b_to_a[i.to] << endl;
//             if (b_to_a[i.to].size() == n / 2) {
//                 // 这里人满了
//                 for (auto j : b_to_a[i.to]) {
//                     if (solve(b_to_a[i.to])) {
//                         // 办不到，舍弃
//                         continue;
//                     }
//                     b_to_a[i.to].push(now);
//                     a_to_b[now] = i.to;
//                     cout << tab << "ans: " << ans << " -> ";
//                     ans += i.value;
//                     cout << ans << endl;

//                     if (now == n) {
//                         cout << tab << "total_ans: " << total_ans << " -> ";
//                         total_ans = max(total_ans, ans);
//                         cout << total_ans << endl;
//                     }
//                     else {
//                         // 继续搜索
//                         solve(now + 1);
//                     }

//                     // 还原
//                     b_to_a[i.to].erase(now);
//                     ans -= i.value;
//                 }
//             }
//             else {
//                 b_to_a[i.to].push_back(now);
//                 a_to_b[now] = i.to;
//                 cout << tab << "ans: " << ans << " -> ";
//                 ans += i.value;
//                 cout << ans << endl;

//                 if (now == n) {
//                     cout << tab << "total_ans: " << total_ans << " -> ";
//                     total_ans = max(total_ans, ans);
//                     cout << total_ans << endl;
//                 }
//                 else {
//                     // 继续搜索
//                     solve(now + 1);
//                 }

//                 // 还原
//                 b_to_a[i.to].erase(now);
//                 ans -= i.value;
//             }
//         }
//     }
//     else {
//         cout << tab << "**RECOOSE**" << endl;
//         // 选过了，重新选择
//         if (pointer[now] == 2) {
//             // 无路可走
//             return 1;
//         }
//         a_to_b[now] = 0;
//         b_to_a[choices[now][pointer[now]].to].erase(now);
//         ans -= choices[now][pointer[now]].value;
//         pointer[now]++;
//         if (b_to_a[choices[now][pointer[now]].to].size() == n / 2) {
//             if (solve(choices[now][pointer[now]].to)) {
//                 return 1;
//             }
//         }
//         a_to_b[now] = choices[now][pointer[now]].to;
//         b_to_a[choices[now][pointer[now]].to] = now;
//         ans += choices[now][pointer[now]].value;
//     }

//     tab = old_tab;
//     return 0;
// }
//                 b_to_a[i.to].push_back(now);
//                 a_to_b[now] = i.to;
//                 cout << tab << "ans: " << ans << " -> ";
//                 ans += i.value;
//                 cout << ans << endl;

//                 if (now == n) {
//                     cout << tab << "total_ans: " << total_ans << " -> ";
//                     total_ans = max(total_ans, ans);
//                     cout << total_ans << endl;
//                 }
//                 else {
//                     // 继续搜索
//                     solve(now + 1);
//                 }

//                 // 还原
//                 b_to_a[i.to].erase(now);
//                 ans -= i.value;
//             }
//         }
//     }
//     else {
//         cout << tab << "**RECOOSE**" << endl;
//         // 选过了，重新选择
//         if (pointer[now] == 2) {
//             // 无路可走
//             return 1;
//         }
//         a_to_b[now] = 0;
//         b_to_a[choices[now][pointer[now]].to].erase(now);
//         ans -= choices[now][pointer[now]].value;
//         pointer[now]++;
//         if (b_to_a[choices[now][pointer[now]].to].size() == n / 2) {
//             if (solve(choices[now][pointer[now]].to)) {
//                 return 1;
//             }
//         }
//         a_to_b[now] = choices[now][pointer[now]].to;
//         b_to_a[choices[now][pointer[now]].to] = now;
//         ans += choices[now][pointer[now]].value;
//     }

//     tab = old_tab;
//     return 0;
// }

void dfs(ll now) {
    for (auto i : choices[now]) {
        if ((ll)b_to_a[i.to].size() == n / 2) continue;
        b_to_a[i.to].insert(now);
        ans += i.value;

        if (now == n) {
            total_ans = max(total_ans, ans);
        }
        else 
            dfs(now + 1);

        ans -= i.value;
        b_to_a[i.to].erase(now);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;

    while (t--) {
        total_ans = LONG_LONG_MIN;
        ans = 0;
        tab = "";

        cin >> n;

        for (ll i=1; i <= n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            choices[i].clear();
            choices[i].push_back({1, a[i][1]});
            choices[i].push_back({2, a[i][2]});
            choices[i].push_back({3, a[i][3]});
            sort(choices[i].begin(), choices[i].end(), greater<choice>());
        }

        // solve(1);

        // 暴力
        dfs(1);

        cout << total_ans << endl;

        // 还原
        haved[1] = haved[2] = haved[3] = 0;
        b_to_a[1].clear();
        b_to_a[2].clear();
        b_to_a[3].clear();
        for (ll i=1; i <= n; i++) {
            a_to_b[i] = 0;
            pointer[i] = 0;
        }
    }

    return 0;
}
