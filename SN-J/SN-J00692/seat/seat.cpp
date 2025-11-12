// ¸¨ÂÖÖÐÑ§ µ­³þÜ² SN-J00692 
#include <bits/stdc++.h>
using namespace std;

int TTT = 1, n, m, a[110], b[110];

bool cmp(int x, int y) {return x > y;}

void mian()
{
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i], b[i] = a[i];
	sort(a + 1, a + 1 + n * m, cmp);
	
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == b[1]) {cout << y << " " << x; return;}
		if(y % 2)
		{
			if(x == n) y++;
			else x++;
		}
		else
		{
			if(x == 1) y++;
			else x--;
		}
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
