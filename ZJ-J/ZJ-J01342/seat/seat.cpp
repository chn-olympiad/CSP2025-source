#include <bits/stdc++.h>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 15;
int n, m;
int a[N][N];

void nxt(int &nx, int &ny)
{
	if(ny & 1) 
	{
		if(nx == n) ny ++ ;
		else nx ++ ;
	}
	else
	{
		if(nx == 1) ny ++ ;
		else nx -- ;
	}
}

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	fr(i, 1, n) fr(j, 1, m)
		cin >> a[i][j];
	
	int nx = 1, ny = 1;
	fr(i, 1, n) fr(j, 1, m)
	{
		if(a[i][j] > a[1][1])
			nxt(nx, ny);
	}
	
	cout << ny << ' ' << nx << '\n';
	
	return 0;
}

