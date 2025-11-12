#include <cstdio>
#include <iostream>

const int N = 1e3 + 10;
int n, q;
std :: string s1[N], s2[N];

bool cmp(int id, int pos, std :: string op) {
    for (int i = 0; i < s1[id].size(); i ++)
        if (s1[id][i] != op[pos + i]) return false;
    return true;
}

bool check(std :: string op1, std :: string op2, int id) {
    int pos = -1;
    for (int i = 0; i < op1.size(); i ++)
        if (cmp(id, i, op1)) pos = i;
    if (pos == -1) return false;
    for (int i = 0; i < s1[id].size(); i ++) op1[i + pos] = s2[id][i];
    return op1 == op2;
}

int main() {

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w",stdout);

    scanf("%d%d", &n, &q);

    if (n > 100) {
        while (q --) printf("0\n");
        return 0;
    }

    for (int i = 1; i <= n; i ++) std :: cin >> s1[i] >> s2[i];
    while (q --) {
        std :: string op1, op2;
        std :: cin >> op1 >> op2;
        int ans = 0;
        for (int i = 1; i <= n; i ++) ans += check(op1, op2, i) ? 1 : 0;
        printf("%d\n", ans);
    }
    
    return 0;
}