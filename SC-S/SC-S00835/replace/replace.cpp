#include <cstdio>
#include <iostream>

const int N = 2e5 + 9;

int n, q, ans = 0;

std::string q1, q2;

std::string s1[N], s2[N];

bool Check(std::string& a, std::string& b, std::string& c, int l, int r) {
    for (int i = 0; i < l; i++)
        if (a[i] != b[i])
            return false;
    int cnt = 0;
    for (int i = l; i < r; i++)
        if (c[cnt++] != b[i])
            return false;
    for (int i = r; i < b.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

void check(std::string& a, std::string& b, int x) {
    int sz = (int)a.size(), end = (int)b.size() - sz;
    for (int i = 0; i <= end; i++) if (a[0] == b[i]) {
        for (int j = 0; j < sz; j++) {
            if (a[j] != b[i + j])
                goto nxt;
        }
        if (Check(q1, q2, s2[x], i, i + s1[x].size()))
            ans ++;
        i += s1[x].size() - 1;
        nxt:;
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> s1[i] >> s2[i];

    while (q --) {
        ans = 0;
        std::cin >> q1 >> q2;
        if (q1.size() == q2.size())
            for (int i = 1; i <= n; i++) 
                check(s1[i], q1, i);
        printf("%d\n", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}