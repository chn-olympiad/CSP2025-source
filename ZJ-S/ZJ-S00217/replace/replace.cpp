#include <bits/stdc++.h>
using namespace std; bool _bg;
int n, q;
namespace trie {
    int nx[10000010][26], tot;
    int ins(const string &s){
        int nw = 0;
        for (char c : s){
            int &o = nx[nw][c - 'a'];
            if (!o)o = ++tot;
            nw = o;
        }
        return nw;
    }
    int fnd(const string &s){
        int nw = 0;
        for (char c : s){
            int o = nx[nw][c - 'a'];
            if (!o)return 0;
            nw = o;
        }
        return nw;
    }
    int tfnd(const string &s){
        int nw = 0;
        for (char c : s){
            int o = nx[nw][c - 'a'];
            if (!o)break;
            nw = o;
        }
        return nw;
    }
    void clear(){
        memset(nx, 0, (tot + 1) * 26 * sizeof(int));
        tot = 0;
    }
    int dfl[10000010], dfr[10000010], tt;
    void dfs(int u = 0){
        if (u == 0)tt = 0;
        dfl[u] = ++tt;
        for (int v : nx[u])if (v)dfs(v);
        dfr[u] = tt;
    }
}
bool splt(const string &s1, const string &s2, string &L, string &M, string &R){
    if (s1 == s2)return 1;
    int Ln = s1.size();
    if (Ln != (int)s2.size())return 1;
    int l = -1, r = -1;
    for (int i = 0; i < Ln; ++i)
        if (s1[i] != s2[i]){
            if (l == -1)l = i;
            r = i + 1;
        }
    assert(~l && ~r);
    M = "", L = "", R = "";
    for (int i = l; i < r; ++i)M += s1[i], M += s2[i];
    for (int i = l - 1; ~i; --i)assert(s1[i] == s2[i]), L += s1[i];
    for (int i = r; i < Ln; ++i)assert(s1[i] == s2[i]), R += s2[i];
    return 0;
}
map<int, int> Mp; int tot;
int fnd(int x){
    if (Mp.count(x))return Mp[x];
    return Mp.emplace(x, ++tot), tot;
}
int fnd2(int x){
    if (!x)return 0;
    if (!Mp.count(x))return 0;
    return Mp[x];
}
vector<pair<string, string> > s[200010];
int rs[200010];
vector<tuple<string, string, int> > qr[200010];
namespace _2dcnt {
    vector<tuple<int, int, int, int> > rct;
    vector<tuple<int, int, int*> > qry;
    vector<int> X, Y;
    void clear(){
        rct.clear();
        qry.clear();
        X.clear();
        Y.clear();
        // clog << "clear" << endl;
    }
    void adrc(int l, int r, int L, int R){
        rct.emplace_back(l, r, L, R);
        // clog << "+" << l << "-" << r << "," << L << "-" << R << endl;
    }
    void adqr(int x, int y, int &p){
        qry.emplace_back(x, y, &p);
        X.emplace_back(x);
        Y.emplace_back(y);
        // clog << "?" << x << "," << y << ">" << &p - rs << endl;
    }
    namespace bit {
        int n, t[200010];
        void bd(int l){
            n = l;
            fill_n(t + 1, n, 0);
        }
        int qr(int p){
            int r = 0;
            for (++p; p; p &= p - 1)r += t[p];
            return r;
        }
        void ad(int p, int v){
            for (++p; p <= n; p += p & -p)t[p] += v;
        }
        void ad(int l, int r, int v){
            ad(l, v);
            ad(r + 1, -v);
        }
    }
    void solve(){
        sort(X.begin(), X.end()), X.erase(unique(X.begin(), X.end()), X.end());
        sort(Y.begin(), Y.end()), Y.erase(unique(Y.begin(), Y.end()), Y.end());
        static vector<tuple<int, int, int> > mdf[200010];
        static vector<pair<int, int*> > pt[200010];
        for (int i = 0, _ = X.size(); i <= _; ++i)mdf[i].clear(), pt[i].clear();
        // clog << "." << endl;
        for (auto &lrLR : rct){
            int &l = get<0>(lrLR);
            int &r = get<1>(lrLR);
            int &L = get<2>(lrLR);
            int &R = get<3>(lrLR);
            l = lower_bound(X.begin(), X.end(), l) - X.begin();
            r = upper_bound(X.begin(), X.end(), r) - X.begin() - 1;
            L = lower_bound(Y.begin(), Y.end(), L) - Y.begin();
            R = upper_bound(Y.begin(), Y.end(), R) - Y.begin() - 1;
            if (l > r || L > R)continue;
            // clog << "+" << l << "-" << r << "," << L << "-" << R << endl;
            mdf[l].emplace_back(L, R, 1);
            mdf[r + 1].emplace_back(L, R, -1);
        }
        for (auto &xyp : qry){
            int &x = get<0>(xyp);
            int &y = get<1>(xyp);
            int *p = get<2>(xyp);
            x = lower_bound(X.begin(), X.end(), x) - X.begin();
            y = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
            // clog << "?" << x << "," << y << endl;
            pt[x].emplace_back(y, p);
        }
        // [[deprecated]] {
        //     for (auto [l, r, L, R] : rct){
        //         for (auto [x, y, p] : qry){
        //             if (l <= x && x <= r && L <= y && y <= R)++*p;
        //         }
        //     }
        //     return;
        // }
        bit::bd(Y.size());
        for (int i = 0, _ = X.size(); i < _; ++i){
            for (auto lrv : mdf[i])bit::ad(get<0>(lrv), get<1>(lrv), get<2>(lrv));
            for (auto yp : pt[i])*get<1>(yp) = bit::qr(get<0>(yp));//, clog << ">" << *get<1>(yp) << endl;
        }
    }
}
// [[deprecated]] bool prefix_of(const string &s, const string &t){ // s is prefix of t
//     if (s.size() > t.size())return 0;
//     return t.substr(0, s.size()) == s;
// }
void solve(const vector<pair<string, string> > &S, const vector<tuple<string, string, int> > &Q){
    if (S.empty() || Q.empty())return;
    // [[deprecated]]
    //     for (auto &&[L, R, id] : Q)
    //         for (auto &&[l, r] : S)
    //             rs[id] += prefix_of(l, L) && prefix_of(r, R); return;
    static int id[200010];
    static int l[200010], r[200010], L[200010], R[200010];
    static int x[200010], y[200010];
    trie::clear();
    for (int i = 0, _ = S.size(); i < _; ++i)
        id[i] = trie::ins(S[i].first);
    trie::dfs();
    for (int i = 0, _ = S.size(); i < _; ++i)
        l[i] = trie::dfl[id[i]], r[i] = trie::dfr[id[i]];
    for (int i = 0, _ = Q.size(); i < _; ++i)
        x[i] = trie::dfl[trie::tfnd(get<0>(Q[i]))];
    trie::clear();
    for (int i = 0, _ = S.size(); i < _; ++i)
        id[i] = trie::ins(S[i].second);
    trie::dfs();
    for (int i = 0, _ = S.size(); i < _; ++i)
        L[i] = trie::dfl[id[i]], R[i] = trie::dfr[id[i]];
    for (int i = 0, _ = Q.size(); i < _; ++i)
        y[i] = trie::dfl[trie::tfnd(get<1>(Q[i]))];
    _2dcnt::clear();
    for (int i = 0, _ = S.size(); i < _; ++i)
        _2dcnt::adrc(l[i], r[i], L[i], R[i]);
    for (int i = 0, _ = Q.size(); i < _; ++i)
        _2dcnt::adqr(x[i], y[i], rs[get<2>(Q[i])]);
    _2dcnt::solve();
}
bool _ed; int main(){
    double mmus = fabs(&_ed - &_bg) / 1024 / 1024;
    assert(mmus < 1100);clog << mmus << "M" << endl;
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    while (n--){
        string s1, s2;
        cin >> s1 >> s2;
        string L, M, R;
        if (splt(s1, s2, L, M, R))continue;
        int u = trie::ins(M);
        s[fnd(u)].emplace_back(move(L), move(R));
    }
    for (int i = 1; i <= q; ++i){
        string t1, t2;
        cin >> t1 >> t2;
        string L, M, R;
        if (splt(t1, t2, L, M, R)){
            rs[i] = 0;
            continue;
        }
        int u = fnd2(trie::fnd(M));
        if (!u){
            rs[i] = 0;
            continue;
        }
        qr[u].emplace_back(move(L), move(R), i);
    }
    for (int i = 1; i <= tot; ++i)solve(s[i], qr[i]);
    for (int i = 1; i <= q; ++i)cout << rs[i] << "\n";
    return 0;
}