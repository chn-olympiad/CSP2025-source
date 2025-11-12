#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 5e6 + 5, M = 2e5 + 5;

struct Trie {
    int son[26], p;
} tr[N], Tr[N];

vector<int> v[N], val[N];
vector<pr> que[N];
int total = 0;
int ans[M];

struct ACAM {
    int root;
    void init() {
        root = ++total;
    }
    void add(string s, int len) {
        int ro = root;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (!tr[ro].son[x]) tr[ro].son[x] = ++total;
            ro = tr[ro].son[x];
        }
        val[ro].pb(len);
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (tr[root].son[i]) {
                tr[tr[root].son[i]].p = root;
                q.push(tr[root].son[i]);
            }
            else tr[root].son[i] = root;
        }
        while (!q.empty()) {
            int ro = q.front();
            q.pop();
            v[tr[ro].p].pb(ro);
            for (int i = 0; i < 26; i++) {
                if (tr[ro].son[i]) {
                    tr[tr[ro].son[i]].p = tr[tr[ro].p].son[i];
                    q.push(tr[ro].son[i]);
                }
                else tr[ro].son[i] = tr[tr[ro].p].son[i];
            }
        }
    }
} T[M];

int root, Total, num = 0;

int add(string s) {
    int ro = root;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        if (!Tr[ro].son[x]) Tr[ro].son[x] = ++Total;
        ro = Tr[ro].son[x];
    }
    if (!Tr[ro].p) {
        Tr[ro].p = ++num;
        T[num].init();
    }
    return Tr[ro].p;
}

int ask(string s) {
    int ro = root;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        if (!Tr[ro].son[x]) return 0;
        ro = Tr[ro].son[x];
    }
    return Tr[ro].p;
}

int cnt[N];

void dfs(int ro) {
    for (auto u : val[ro]) cnt[u]++;
    for (auto u : que[ro]) ans[u.second] += cnt[u.first];
    for (auto u : v[ro]) dfs(u);
    for (auto u : val[ro]) cnt[u]--;
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    root = Total = 1;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2) continue;
        int l = 0, r = s1.size() - 1;
        while (s1[l] == s2[l]) l++;
        while (s1[r] == s2[r]) r--;
        string t = "";
        for (int i = l; i <= r; i++) t += s1[i];
        for (int i = l; i <= r; i++) t += s2[i];
        int id = add(t);
        T[id].add(s1, s1.size() - r);
    }
    for (int i = 1; i <= num; i++) T[i].build();
    for (int i = 1; i <= q; i++) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() == t2.size()) {
            ll ans = 0;
            int l = 0, r = t1.size() - 1;
            while (t1[l] == t2[l]) l++;
            while (t1[r] == t2[r]) r--;
            string t = "";
            for (int j = l; j <= r; j++) t += t1[j];
            for (int j = l; j <= r; j++) t += t2[j];
            int id = ask(t);
            if (id) {
                int ro = T[id].root;
                for (int j = 0; j < t1.size(); j++) {
                    ro = tr[ro].son[t1[j] - 'a'];
                    if (j >= r) que[ro].pb({j - r + 1, i});
                }
            }
        }
    }
    for (int i = 1; i <= num; i++) dfs(T[i].root);
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}