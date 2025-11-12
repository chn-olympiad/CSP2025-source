#include<bits/stdc++.h>
#define fup(i, bg, ed) for(int i = (bg); i <= (ed); i++)
#define fdn(i, bg, ed) for(int i = (bg); i >= (ed); i--)
typedef long long lld;
using namespace std;

struct AutoIO {
    AutoIO() {
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    ~AutoIO() {
        cout.flush();
        #ifdef Local
        cerr << 1. * clock() / CLOCKS_PER_SEC << "ms" << "\n";
        #endif
    }
}__cdl_auto_io;

struct Pair {
    string A, B;
    string C, D;
};
const int N = 2e5 + 10;
const int SZ = 1e7 + 10;

Pair mdf[N], qry[N];
int n, q;
int chl[SZ][27], tot = 1;
int id[SZ];
int pid;
vector<int> mdfs[N*2], qrys[N*2];
int mL[N], mR[N];
int qL[N], qR[N];
int ans[N];
struct Scan {
    int x, L, R, opt, id;
};
bool operator < (const Scan& l, const Scan& r) {
    if(l.x == r.x) return abs(l.opt) > abs(r.opt);
    return l.x < r.x;
}

void build(string& s, string& t, Pair& pr) {
    if(s == t) return ;
    int sz = s.size() - 1;
    int L = 0, R = sz;
    while(s[L] == t[L]) ++L;
    while(s[R] == t[R]) --R;
    fup(i, 0, L-1) pr.A += s[i];
    fup(i, R+1, sz) pr.B += s[i];
    fup(i, L, R) pr.C += s[i];
    fup(i, L, R) pr.D += t[i];
}

namespace Work {
    int tot, dfn[SZ], out[SZ], pdfn;
    int nnode() {
        ++tot;
        // fup(c, 0, 25) chl[tot][c] = 0;
        return tot;
    }
    void dfs(int u, int dep = 0) {
        // cerr << u << " " << dep << endl;
        dfn[u] = ++pdfn;
        fup(c, 0, 25) if(chl[u][c]) dfs(chl[u][c], dep + 1);
        out[u] = pdfn;
    }
    void print(int u, int dep = 0) {
        cerr << u << " " << dep << endl;
        fup(c, 0, 25) if(chl[u][c]) dfs(chl[u][c], dep + 1);
    }
    void init() {
        tot = 1;
        pdfn = 0;
    }
    int ins(string& s, bool rev) {
        if(rev) reverse(s.begin(), s.end());
        int u = 1;
        for(auto ch : s) {
            int bit = ch - 'a';
            if(!chl[u][bit]) chl[u][bit] = nnode();
            u = chl[u][bit];
        }
        return u;
    }
    int get(string& s, bool rev) {
        if(rev) reverse(s.begin(), s.end());
        int u = 1;
        for(auto ch : s) {
            int bit = ch - 'a';
            if(!chl[u][bit]) return u;
            u = chl[u][bit];
        }
        return u;
    }
}
namespace BIT {
    int c[SZ];
    void add(int x, int v) {
        for(; x < SZ; x += x & (-x)) c[x] += v;
    }
    int qry(int x) {
        int res = 0;
        for(; x; x -= x & (-x)) res += c[x];
        return res;
    }
}

main() {
    cin >> n >> q;
    fup(i, 1, n) {
        string S, T;
        cin >> S >> T;
        build(S, T, mdf[i]);
    }
    fup(i, 1, q) {
        string S, T;
        cin >> S >> T;
        // if(i == 102) cerr << S << "\n" << T << endl;
        if(S.size() != T.size()) continue;
        build(S, T, qry[i]);
    }

    fup(i, 1, n) {
        if(mdf[i].C.size()) {
            int u = 1;
            for(auto ch : mdf[i].C) {
                int bit = ch - 'a';
                if(!chl[u][bit]) chl[u][bit] = ++tot;
                u = chl[u][bit];
            }
            int bit = 26;
            if(!chl[u][bit]) chl[u][bit] = ++tot;
            u = chl[u][bit];
            for(auto ch : mdf[i].D) {
                int bit = ch - 'a';
                if(!chl[u][bit]) chl[u][bit] = ++tot;
                u = chl[u][bit];
            }
            if(!id[u]) id[u] = ++pid;
            mdfs[id[u]].emplace_back(i);
        }
    }
    fup(i, 1, q) {
        if(qry[i].C.size()) {
            int u = 1;
            for(auto ch : qry[i].C) {
                int bit = ch - 'a';
                if(!chl[u][bit]) chl[u][bit] = ++tot;
                u = chl[u][bit];
            }
            int bit = 26;
            if(!chl[u][bit]) chl[u][bit] = ++tot;
            u = chl[u][bit];
            for(auto ch : qry[i].D) {
                int bit = ch - 'a';
                if(!chl[u][bit]) chl[u][bit] = ++tot;
                u = chl[u][bit];
            }
            if(!id[u]) id[u] = ++pid;
            qrys[id[u]].emplace_back(i);
        }
    }
    fup(i, 1, tot) fup(c, 0, 26) chl[i][c] = 0;
    fup(i, 1, tot) if(id[i]) {
        // cerr << "id: " << i << endl;
        // for(auto id : mdfs[id[i]]) cerr << id << " ";
        // cerr << "\n";
        // for(auto id : qrys[id[i]]) cerr << id << " ";
        // cerr << "\n";
        Work::init();
        for(auto j : mdfs[id[i]]) {
            mL[j] = Work::ins(mdf[j].A, 1);
            mR[j] = Work::ins(mdf[j].B, 0);
        }
        for(auto j : qrys[id[i]]) {
        //     if(j == 101) {
        // cerr << "id: " << i << endl;
        // for(auto id : mdfs[id[i]]) cerr << id << " ";
        // cerr << "\n";
        // for(auto id : qrys[id[i]]) cerr << id << " ";
        // cerr << "\n";
        //     }
            qL[j] = Work::get(qry[j].A, 1);
            qR[j] = Work::get(qry[j].B, 0);
        }
        // if(Work::tot > 1) {
        //     cerr << Work::tot << "\n";
        //     Work::print(1);
        // }
        Work::dfs(1);
        vector<Scan> sc;
        for(auto j : mdfs[id[i]]) {
            // cerr << mdf[j].A << " " <<
            sc.push_back({ Work::dfn[mR[j]], Work::dfn[mL[j]], Work::out[mL[j]], 1, 0 });
            sc.push_back({ Work::out[mR[j]] + 1, Work::dfn[mL[j]], Work::out[mL[j]], -1, 0 });
        //     if(i == 1233) {
        //         cerr << Work::dfn[mL[j]] << ", " << Work::out[mL[j]] << endl;
        //         cerr << Work::dfn[mR[j]] << ", " << Work::out[mR[j]] << endl;

        //     }
        }
        for(auto j : qrys[id[i]]) {
            sc.push_back({ Work::dfn[qR[j]], Work::dfn[qL[j]], Work::dfn[qL[j]], 0, j });

            // if(j == 101) {
            //     cerr << Work::dfn[qL[j]] << endl;
            //     cerr << Work::dfn[qR[j]] << endl;
            //     for(auto j : mdfs[id[i]]) {

            // }
        }
        sort(sc.begin(), sc.end());
        for(auto[x, L, R, opt, j] : sc) {
            if(opt == 0) {
                ans[j] = BIT::qry(L);
            } else {
                BIT::add(L, opt);
                BIT::add(R+1, -opt);
            }
        }
        for(auto[x, L, R, opt, j] : sc) {
            if(opt != 0) {
                BIT::add(L, -opt);
                BIT::add(R+1, opt);
            }
        }
        fup(i, 1, Work::tot) fup(c, 0, 25) chl[i][c] = 0;
    }
    fup(i, 1, q) cout << ans[i] << "\n";
}