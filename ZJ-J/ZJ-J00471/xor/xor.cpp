#include <bits/stdc++.h>
#define lld long long
using namespace std;

struct node {
    lld x;
    lld parent, nl, nr;
};

lld n, k, tree_size = 1, ans;
vector<lld> a;
vector<node> tree;
map<pair<lld, lld>, int> m;
vector<pair<lld, lld> > range;
vector<bool> used;

void build(lld idx, lld l, lld r) {
    if (l == r) {
        tree[idx].x = a[l];
        m[{l, r}] = tree[idx].x;
        return;
    }
    lld mid = (l + r) >> 1;
    tree_size++;
    tree[tree_size].parent = idx;
    tree[idx].nl = tree_size;
    tree_size++;
    tree[tree_size].parent = idx;
    tree[idx].nr = tree_size;
    build(tree[idx].nl, l, mid);
    build(tree[idx].nr, mid + 1, r);

    tree[idx].x = tree[tree[idx].nl].x ^ tree[tree[idx].nr].x;
    m[{l, r}] = tree[idx].x;
}

int getVal(lld l, lld r) {
    if (m.find({l, r}) != m.end()) return m[{l, r}];
    lld mid = (l + r) >> 1;
    lld res = getVal(l, mid) ^ getVal(mid + 1, r);
    m[{l, r}] = res;
    return res;
}

bool cmp(pair<lld, lld> x, pair<lld, lld> y) {
    if (x.second - x.first == y.second - y.first) {
        if (x.first == y.first) {
            return x.first < y.first;
        } else {
            return x.second < y.second; 
        }
    } else {
        return x.second - x.first < y.second - y.first;
    }

}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n + 1);
    tree.resize(2 * n + 1);
    used.resize(n + 1);

    for (lld i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (lld i = 1; i <= n; i++) {
        for (lld j = 1; j <= i; j++) {
            if (getVal(j, i) == k) range.push_back({j, i});
        }
    }

    sort(range.begin(), range.end(), cmp);

    for (auto i : range) {
        bool flag = true;
        for (lld j = i.first; j <= i.second; j++) {
            if (used[j]) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        for (lld j = i.first; j <= i.second; j++) {
            used[j] = true;
        }
        ans++;
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    
    return 0;
}