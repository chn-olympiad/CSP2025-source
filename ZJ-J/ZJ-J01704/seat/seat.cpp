#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N];
int n, m;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n * m; i ++)
		scanf("%d", &a[i]);
	int xR = a[0], idR = 0;
	sort(a, a + n * m, greater<int>());
	
	for(int i = 0; i < n * m; i ++)
		if(a[i] == xR)
		{
			idR = i;
			break;
		}
	
	int c, r;
	c = idR / n + 1;
	r = idR % n + 1;
	if(c % 2 == 0) r = n + 1 - r;
	printf("%d %d\n", c, r);
	
	
	
	
	return 0;
}
