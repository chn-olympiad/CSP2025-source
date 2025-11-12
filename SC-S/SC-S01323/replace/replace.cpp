#include <bits/stdc++.h>
using namespace std;
bool Mbe;
typedef long long ll;
const int N = 200005, M = 6000005;
int n, q, ct;
vector<int> rts;
int ch[M][27], fil[M], cnt[M];
int dct = 1, dic[M][26], did[M];
void DInsert(string &str) {
    int p = 1;
    for (char C : str) {
        int c = C - 'a';
        if (!dic[p][c]) dic[p][c] = ++dct;
        p = dic[p][c];
    }
    did[p] = ++ct;
}
int DQuery(string &str) {
    int p = 1;
    for (char C : str) {
        int c = C - 'a';
        if (!dic[p][c]) return 0;
        p = dic[p][c];
    }
    return did[p];
}
void Insert(int p, string str) {
    for (char C : str) {
        int c = C - 'a';
        if (!ch[p][c]) ch[p][c] = ++ct;
        p = ch[p][c];
    }
    ++cnt[p];
}
void BuildFail(int p) {
    queue<int> que;
    for (int i = 0; i <= 26; ++i) 
        if (ch[p][i]) fil[ch[p][i]] = p, que.push(ch[p][i]);
        else ch[p][i] = p;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        int f = fil[u];
        cnt[u] += cnt[f];
        for (int i = 0; i <= 26; ++i) {
            if (ch[u][i]) que.push(ch[u][i]), fil[ch[u][i]] = ch[f][i];
            else ch[u][i] = ch[f][i];
        }
    }
}
int Query(int p, string str) {
    int sum = 0;
    for (char C : str) {
        int c = C - 'a';
        p = ch[p][c];
        sum += cnt[p];
    }
    return sum;
}
void f(string &a, string &b, bool op) {
    int len = (int)a.size();
    if (!op && a.size() != b.size()) return cout << "0\n", void();
    int l = -1, r = -1;
    for (int i = 0; i < len; ++i)
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    if (l == -1) return;
    for (int i = len - 1; i >= 0; --i)
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    string A, B, P, S;
    for (int i = l; i <= r; ++i) A.push_back(a[i]), B.push_back(b[i]);
    A += B;
    for (int i = 0; i < l; ++i) P.push_back(a[i]);
    for (int i = r + 1; i < len; ++i) S.push_back(a[i]);
    if (op) {
        int p = DQuery(A);
        if (p == 0) {
            DInsert(A), p = ct;
            rts.push_back(ct);
        }
        Insert(p, P + '{' + S);
    } else {
        int p = DQuery(A);
        if (p != 0) {
            cout << Query(p, P + '{' + S) << '\n';
        } else {
            cout << "0\n";
        }
    }
}
bool Med;
int main() {
    // cerr << (&Mbe - &Med) / 1024. / 1024. << "MB\n";
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        f(a, b, 1);
    }
    for (int v : rts) BuildFail(v);
    while (q--) {
        string a, b;
        cin >> a >> b;
        f(a, b, 0);
    }
    return 0;
}