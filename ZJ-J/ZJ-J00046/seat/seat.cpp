#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 105;

int n, m;
int a[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", a + i);
	int k = a[1], pos;

	sort(a + 1, a + 1 + n * m, greater<int>());
	
	for (int i = 1; i <= n * m; i++)
		if(a[i] == k)
			pos = i;
			
	int c = (pos + n - 1) / n;
	int r = (c & 1) ? (pos % n) : (n - pos % n + 1);
	if (pos % n == 0)
		r = (c & 1) ? n : 1;
	
	printf("%d %d", c, r);

	return 0;
}
