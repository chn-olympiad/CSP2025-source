#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int w[N], p[N][N];
int n, m;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> w[i];
	int s = w[1];
	sort(w + 1, w + n * m + 1, greater<int>());
	for(int i = 1; i <= n * m; i ++) 
	{
		if(s == w[i])
		{
			s = i;
			break;
		}	
	}
	int g = s / n, f = s % n;
	if(f == 0)
	{
		cout << g << " " << (g % 2 == 1 ? n : 1);
	}
	else
	{
		cout << g + 1<< " " << (g % 2 == 1 ? n - f + 1 : f);
	}
	return 0;
}
