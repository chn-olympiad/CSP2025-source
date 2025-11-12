#include <bits/stdc++.h>
using namespace std;
int n, m, ans, x, y;
struct student
{
	int k, sc;
}s[101];
bool cmp(student a, student b)
{
	return a.sc > b.sc;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n*m; i ++)
	{
		scanf("%d", &s[i].sc);
		s[i].k = i;
	}
	sort(s, s+n*m, cmp);
	for(int i = 0; i < n*m; i ++)
		if(s[i].k == 0)
		{
			ans = i;
			break;
		}
	x = ans/n+1, y = ans-(x-1)*n+1;
	cout << x <<' '<< (x % 2 == 1 ? y : n-y+1) << endl;
	return 0;
}