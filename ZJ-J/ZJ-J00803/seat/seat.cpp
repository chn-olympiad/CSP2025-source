#include<bits/stdc++.h>
using namespace std;
int n, m, a[110];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int x = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1, j = n * m; i < j; i++, j--)
		swap(a[i], a[j]);
	int w = -1;
	for(int i = 1; i <= n * m && w == -1; i++)
		if(a[i] == x) w = i;
	int k, t = (w - 1) % n + 1;
	if(w % m == 0) k = w / m;
	else k = w / m + 1;
	if(k % 2 == 0) t = n - t + 1;
	printf("%d %d", k, t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
