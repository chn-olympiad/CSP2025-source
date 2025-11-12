#include<bits/stdc++.h>
using namespace std;

int a[110];

bool cmp(int x, int y) 
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int z = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cur1 = 1, cur2 = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(cur2 < m && cur1 % 2 == 1) cur2++;
		else if(cur2 > 1 && cur1 % 2 == 0) cur2--;
		else if(cur2 == m || cur2 == 1) cur1++;
		if(a[i] == z)
		{
			cout << cur1 << " " << cur2;
			break;
		}
	}
	return 0;
}
