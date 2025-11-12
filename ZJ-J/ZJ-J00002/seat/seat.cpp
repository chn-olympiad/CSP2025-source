/* ×ùÎ» */
                
#include <bits/stdc++.h>
#define regint register int
using namespace std;

int n, m;
int a[105];
int main(){
	int c, k, x, y;
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(regint i = 0; i < n*m; i++)
		scanf("%d", a+i);
	
	k = a[0];
	sort(a, a+n*m);
	c = n*m-(lower_bound(a, a+n*m, k) - a);
	x = (c-1) / n + 1;
	if(x & 1)
		y = (c-1) % n + 1;
	else
		y = n - (c-1) % n;
	printf("%d %d", x, y);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
