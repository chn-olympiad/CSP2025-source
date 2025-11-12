#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], R;
bool cmp(int a, int b)
{
	return b > a;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= m*n;i++)
		cin >> a[i];
	R = a[i];
	sort(a + 1, a + 1 + n cmp);
	for(int i = 1;i <= m*n;i++)
	{
		if(a[i] == R) R = i;
	}
	if(R % n == 0)
	{
		
	}
	return 0;
}
