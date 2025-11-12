#include<bits/stdc++.h>
using namespace std;
int n , m , nm = 0 , c , r = 2;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin >> n >> m;
	int mn[10087];
	for(int i = 0; i < n * m; i++)
	{
		cin >> mn[i];
	}
	for(int i = 1; i < n * m; i++)
	{
		if(mn[0] < mn[i])
		{
			nm++;
		}
	}
	while (nm > n)
	{
		nm -= n;
		r++;
	}
	c = nm;
	cout << c << " " << r;
}
