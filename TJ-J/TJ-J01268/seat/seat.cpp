#include<bits/stdc++.h>
using namespace std;
long long n, m;
int a[100], w, x, y, sf;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	y = 1;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	w = a[1];
	sort(a + 1, a + 1 + n * m);
	for(int i = n * m; i >= 1; i--)
	{
		if(sf == 0)x++;
		else x--;
		if(a[i] == w)
		{
			
			cout << y << " " << x;
		}
		if((sf == 0 && x == n) || (sf == 1 && x == 1))
		{ 
			y++;
			if(y % 2 == 1)
			{
				sf = 0;
				x = 0;
			}
			else
			{
				sf = 1;
				x = m + 1;
			}
		}
	 } 
	return 0;
} 
