#include <bits/stdc++.h>
using namespace std;

int n, cnt;
long long maxv;
int a[500005], p[500005];

void dfs(int num, int i, int k, long long sum, long long maxv) {
    if(k > num) return ;
    if(k == num) {
        if(maxv * 2 < sum) cnt++;
        return ;
    }
    for(int j = i + 1; j <= n; j++) {
        p[k + 1] = a[j];
        long long aj = a[j];
        dfs(num, j, k + 1, sum + a[j], max(aj, maxv));
    }
}

int main()
{
	freopen("ploygon.in", "r", stdin);
	freopen("ploygon.out", "w", stdout);
	scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 3; i <= n; i++) {
        dfs(i, 0, 0, 0ll, 0ll);
    }
    cout << cnt % 998244353 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
