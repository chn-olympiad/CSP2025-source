#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n * m;i++)
		scanf("%d", &a[i]);
	int rnk = 0;
	for (int i = 1;i < n * m;i++)
		if (a[i] > a[0]) rnk++;
	printf("%d ", rnk / n + 1);
	if ((rnk / n + 1) % 2 == 0)
		printf("%d\n", n - rnk % n);
	else printf("%d\n", rnk % n + 1);
	return 0;
}
