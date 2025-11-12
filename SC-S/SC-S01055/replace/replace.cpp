#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 2e5 + 5;
const ll base = 13131, mod = 1e9 + 7;

bool flg = 1;
int n, q;
pair<string, string> op[N];
map<int, int> cnt;

bool check(string a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] != 'a' && a[i] != 'b')
            return 0;
        if (a[i] == 'b')    
            cnt ++;
    }
    if (cnt == 1)
        return 1;
    else 
        return 0;
}

void solve(string a, string b) {
    int pos1, pos2;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] == 'b') {
            pos1 = i;
            break;
        }
    }
    for (int i = 0; i < b.size(); i ++) {
        if (b[i] == 'b') {
            pos2 = i;
            break;
        }
    }
    cout << cnt[pos1 - pos2] << "\n";
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> op[i].first >> op[i].second;
        flg = check(op[i].first);
        flg = check(op[i].second);
    }
    if (flg) {
        for (int i = 1; i <= n; i ++) {
            int pos1, pos2;
            for (int j = 0; j < op[i].first.size(); j ++) {
                if (op[i].first[j] == 'b') {
                    pos1 = j;
                    break;
                }
            }
            for (int j = 0; j < op[i].second.size(); j ++) {
                if (op[i].second[j] == 'b') {
                    pos2 = j;
                    break;
                }
            }
            cnt[pos1 - pos2] ++;
        }
    }
    for (int i = 1; i <= q; i ++) {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size()) {
            cout << "0\n";
            continue;
        }
        int len = a.size(), tim = 0;
        if (check(a) && check(b) && flg) {
            solve(a, b);
            continue;
        }
        for (int j = 1; j <= n; j ++) {
            for (int k = 0; k < a.size() && len - k >= op[j].first.size(); k ++) {
                if (a.substr(0, k) != b.substr(0, k)) {
                    break;
                }
                if (a.substr(k, op[j].first.size()) == op[j].first && 
                    b.substr(k, op[j].first.size()) == op[j].second &&
                    a.substr(k + op[j].first.size(), len - k - op[j].first.size()) == b.substr(k + op[j].first.size(), len - k - op[j].first.size())) {
                        tim ++;
                    }
                    
            }
        }
        cout << tim << "\n";
    }
    return 0;
}