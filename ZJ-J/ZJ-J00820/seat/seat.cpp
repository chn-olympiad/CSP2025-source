#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;
int n, m, a[MAXN], r, row, col;
bool tongpai[101];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    memset(tongpai, 0, sizeof tongpai);
    cin >> n >> m;
    for (int i = 0; i < n * m; ++ i)
	{
		cin >> a[i];
		tongpai[a[i]] = 1;
	}
    r = a[0];
    int cnt = 0;
    for (int i = 100; i >= 0; -- i)
    	if (tongpai[i]) a[cnt ++] = i;
    for (int i = 0; i < n * m; ++ i)
        if (a[i] == r) { r = i + 1; break; }
    col = (r - 1) / n + 1;
    row = (r - 1) % n + 1;
    if (!(col % 2)) row = n - row + 1;
    printf("%i %i\n", col, row);
    fclose(stdin);
    fclose(stdout);
    return 0;
}