#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
long long a[N], R, n, m;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//ios::sync_with_stdio(false)
	//cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i=1; i<=n*m; i++)
	{

		if(a[i] == R)
		{
			
			cout << (i-1)/n+1 << " ";
			int k = (i-1)/n+1;
			if(k % 2 == 1)
			{
				cout << (i-1)%n+1;
			}
			else
			{
				cout << n-(i-1)%n;
			}
			
		}
		
	}
	
	return 0;
}
 
