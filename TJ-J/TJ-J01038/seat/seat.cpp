#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int len = n * m;
	int b[len] = {0};
	for (int i = 0; i < len; i++) cin >> b[i];
	int r = b[0];
	sort(b, b + len);
	int x = 1, y = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (b[i] == r) break;
		if (y % 2 == 1)
		{
			if (x == n)
			{
				y++;
			}
			else x++;
		}
		else
		{
			if (x == 1)
			{
				y++;
			}
			else x--;
		}
	}
	cout << x << " " << y;
	return 0;
}
