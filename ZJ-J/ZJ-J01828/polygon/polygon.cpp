#include<cstdint>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct inputImpl {
    uint64_t var;
    uint64_t cnt;
};
vector<inputImpl> edges;
uint64_t edgesize;
uint64_t n;
uint64_t mod = 998244353;

uint64_t do_force() {
    struct processImpl {
        uint64_t processed;
        uint64_t sum;
        uint64_t max;
    };
    uint64_t cnt = 0;
    vector<processImpl> q;
    processImpl src;
    src.processed = 0;
    src.sum = 0;
    src.max = 0;
    q.emplace_back(src);
    while (q.size() != 0) {
        processImpl p = *q.begin();
        q.erase(q.begin());
        if (p.sum > 2 * p.max && p.processed >= 3) {
            // wrong answer (
            cnt += 1;
            if (cnt >= mod) {
                cnt %= mod;
            }
        }
        if (p.processed == edgesize) {
            continue;
            // there is nothing to do.
            // why do you continue process??
        }
        uint64_t next = p.processed + 1;
        auto nextIT = (edges.begin() + next);
        for (uint64_t i = 0; i <= nextIT->cnt; ++i) {
            processImpl nextP;
            nextP.processed = next;
            nextP.sum = p.sum + nextIT->var * i;
            if (i == 0) {
                nextP.max = p.max;
            } else {
                nextP.max = max(p.max, nextIT->var);
            }
            q.emplace_back(nextP);
        }
    }
    return cnt;
}

int main() {
    freopen("polygon.in", "r", stdin);
#ifndef kaFkailoVeyou
    freopen("polygon.out", "w", stdout);
#endif
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    inputImpl zero;
    zero.var = 0;
    zero.cnt = 0;
    edges.emplace_back(zero);
    for (uint64_t i = 1; i <= n; ++i) {
        inputImpl buf;
        cin >> buf.var;
        buf.cnt = 1;
        edges.emplace_back(buf);
    }
    sort(edges.begin(), edges.end(), [](inputImpl a, inputImpl b) {
        return a.var < b.var;
    });
    for (auto it = edges.begin(); it != edges.end() - 1; ) {
        if ((it + 1)->var == it->var) {
            edges.erase(it + 1);
            it->cnt += 1;
        } else {
            it += 1;
        }
    }
    edgesize = edges.size() - 1;
    cout << do_force() << '\n';
    cout.flush();
    fclose(stdin);
#ifndef kaFkailoVeyou
    fclose(stdout);
#endif
    return 0;
}