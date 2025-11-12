#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
typedef long long ll;
const int N = 509;
const int P = 998244353;
int n, m, ans;
int a[N], c[N];
bool s[N];
void dfs (int x, int p) {
    if (x > n) {
        if (p >= m) ++ans;
        return;
    }
    for (int i = 1; i <= n - x + 1; i++) {
        swap(a[i], a[n - x + 1]);
        if (c[a[n - x + 1]] > x - p - 1 && s[x])
            dfs(x + 1, p + 1);
        else
            dfs(x + 1, p);
        swap(a[i], a[n - x + 1]);
    }
}
int main () {
    scanf("%d%d", &n, &m);
    scanf("\n");
    int res = 0;
    for (int i = 1; i <= n; i++)
        s[i] = getchar() - '0', res += s[i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    if (res < m) {
        printf("0\n");
        return 0;
    }
    if (res == n) {
        ans = 1;
        for (int i = 1; i <= n; i++)
            ans = (ll)ans * i % P;
        printf("%d\n", ans);
    } else {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}