// Go in my style.
// Not afraid to dark.
// Beat.

#include <bits/stdc++.h>
using namespace std;

namespace io {
    int pos;
    inline int read(int &p = pos) {
        static int v; static char c;
        p = 0, v = 1, c = getchar();
        while (!isdigit(c)) {
            if (c == '-') v = -1;
            c = getchar();
        }
        while (isdigit(c)) {
            p = (p << 1) + (p << 3) + (c - 48);
            c = getchar();
        }
        return p = v == 1 ? p : -p;
    }
    inline void write(int x) {
        static int sta[65], top;
        if (x < 0) x = -x, putchar('-');
        top = 0;
        do {
            sta[++top] = x % 10;
            x /= 10;
        } while(x);
        while (top) putchar(sta[top--] + 48);
    }
    inline void readstring(string &s) {
    	static char c; c = getchar();
    	while (c < 'a' || c > 'z') c = getchar();
    	while (c >= 'a' && c <= 'z') {
    		s += c;
    		c = getchar();
		}
	}
}

const int N = 2e5 + 5, LEN = 5e6 + 5;
int n, q, ans[N + 5];
string s[N + 5][2], t[N + 5][2];
int qpb[N + 5];

namespace TrieB {
    const int P = LEN + 5;
    int tot, fa[P];
    map<int, int> to[P];
    inline int newnode() {
        ++tot;
        to[tot].clear();
        fa[tot] = -1;
        return tot;
    }
    inline int toc(int p, int Trs) {
        if (!to[p].count(Trs)) {
            to[p][Trs] = newnode();
            fa[tot] = p;
        }
        return to[p][Trs];
    }
}
namespace TrieA {
    const int P = LEN + 5;
    int tot;
    vector<int> codB[P];
    vector<int> que[P];
    map<int, int> to[P];
    inline int newnode() {
        ++tot;
        to[tot].clear();
        codB[tot].clear();
        return tot;
    }
    inline int toc(int p, int Trs) {
        if (!to[p].count(Trs)) to[p][Trs] = newnode();
        return to[p][Trs];
    }
    int tonB[P];
    void sol(int p) {
        for (int o : codB[p]) ++tonB[o];
        for (int qi : que[p]) {
            int u = qpb[qi]; ans[qi] = 0;
            while (u != -1) {
                ans[qi] += tonB[u];
                u = TrieB::fa[u];
            }
        }
        for (pair<int, int> e : to[p])
            sol(e.second);
        for (int o : codB[p]) --tonB[o];
    }
}

namespace TrieC {
    const int P = LEN + 5;
    int tot, rootA[P], rootB[P];
    map<int, int> to[P];
    inline int newnode() {
        ++tot;
        rootA[tot] = rootB[tot] = -1;
        to[tot].clear();
        return tot;
    }
    inline int toc(int p, int Trs) {
        if (!to[p].count(Trs)) to[p][Trs] = newnode();
        return to[p][Trs];
    }
    void sol(int p) {
        if (rootA[p] != -1 && rootB[p] != -1) TrieA::sol(rootA[p]);
        for (pair<int, int> e : to[p])
            sol(e.second);
    }
}

inline void Insert(string &a, string &b) {
    if (a == b) return ;
    int l = 0, r = (int)a.size() - 1;
    while (a[l] == b[l]) ++l;
    while (a[r] == b[r]) --r;

    int p = 0;
    for (int i = l; i <= r; ++i) {
        int Trs = (a[i] - 'a') * 26 + (b[i] - 'a');
        p = TrieC::toc(p, Trs);
    }

    if (TrieC::rootA[p] == -1) TrieC::rootA[p] = TrieA::newnode();
    int pA = TrieC::rootA[p];
    for (int i = l - 1; i >= 0; --i)
        pA = TrieA::toc(pA, a[i] - 'a');

    if (TrieC::rootB[p] == -1) TrieC::rootB[p] = TrieB::newnode();
    int pB = TrieC::rootB[p];
    for (int i = r + 1; i < (int)a.size(); ++i)
        pB = TrieB::toc(pB, a[i] - 'a');

    TrieA::codB[pA].emplace_back(pB);
}
inline void Addque(string &a, string &b, int i) {
    if (a.size() != b.size()) return ;
    if (a == b) return ;
    int l = 0, r = (int)a.size() - 1;
    while (a[l] == b[l]) ++l;
    while (a[r] == b[r]) --r;

    int p = 0;
    for (int i = l; i <= r; ++i) {
        int Trs = (a[i] - 'a') * 26 + (b[i] - 'a');
        p = TrieC::toc(p, Trs);
    }

    if (TrieC::rootA[p] == -1) TrieC::rootA[p] = TrieA::newnode();
    int pA = TrieC::rootA[p];
    for (int i = l - 1; i >= 0; --i)
        pA = TrieA::toc(pA, a[i] - 'a');

    if (TrieC::rootB[p] == -1) TrieC::rootB[p] = TrieB::newnode();
    int pB = TrieC::rootB[p];
    for (int i = r + 1; i < (int)a.size(); ++i)
        pB = TrieB::toc(pB, a[i] - 'a');

    qpb[i] = pB;
    TrieA::que[pA].emplace_back(i);
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
    io::read(n), io::read(q);
    for (int i = 1; i <= n; ++i) {
    	io::readstring(s[i][0]);
    	io::readstring(s[i][1]);
	}
    for (int i = 1; i <= q; ++i) {
    	io::readstring(t[i][0]);
    	io::readstring(t[i][1]);
	}
    for (int i = 1; i <= n; ++i) Insert(s[i][0], s[i][1]);
    for (int i = 1; i <= q; ++i) Addque(t[i][0], t[i][1], i);
    TrieC::sol(0);
    for (int i = 1; i <= q; ++i) io::write(ans[i]), putchar('\n');
    return 0;
}