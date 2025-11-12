#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
int a[1010];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	ll lie = 1;
	ll hang = 1;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	while(lie == m && hang == n)
	{
		if(hang < n)
		{
			hang++;
		}
		if(hang >= n)
		{
			lie++;
			hang = 0;
		}
	}
	
	cout<< lie << " " <<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
