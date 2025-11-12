#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000], cnt;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
    for(int i = 2; i <= n * m; i++) if(a[1] < a[i]) cnt++;
    cnt++;
    cout << (int(cnt / n) + (cnt % n == 0 ? 0 : 1)) << " ";
    if((int(cnt / n) + (cnt % n == 0 ? 0 : 1)) % 2 == 0) cout << n - cnt % n + 1 << endl;
    else cout << (cnt - 1) % n + 1 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
