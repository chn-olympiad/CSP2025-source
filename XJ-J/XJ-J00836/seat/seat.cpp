#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[110], mp[20][20];

bool cmp(int x, int y);

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> a[i];
	int little_R = a[0];
	sort(a, a + n * m, cmp);
//	for (int i = 0; i < n * m; i++)
//		cout << a[i] << ' ';
//	cout << endl;
	int cnt = -1;
	for (int i = 0; i < n * m; i++)
	{
		if (a[i] == little_R)
			cnt = i + 1;
	}
//	cout << cnt << endl;
	int col = -1, row = -0x3f;
	if (cnt % n != 0)
	{
		col = cnt / n + 1;
		if (col % 2 == 0) row = n - cnt % n + 1;
		else row = cnt % n;
	}
	else
	{
		col = cnt / n;
		if (col % 2 == 0) row = 1;
		else row = n;
	}
	cout << col << ' ' << row << endl;
	return 0;
}

bool cmp(int x, int y)
{
	return x > y;
}
 
