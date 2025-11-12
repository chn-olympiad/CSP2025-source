#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], cnt = 1, x, y;
void fnd(int num)
{
	y = (num - 1) / n + 1;
	x = (num - 1) % n + 1;
	if(y % 2 == 0)	x = n - x + 1;
	return ;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	for(int i = 2; i <= n * m; i++)
		if(a[i] > a[1])
			cnt++;
	fnd(cnt);
	cout << y << " " << x;
	return 0;
}
