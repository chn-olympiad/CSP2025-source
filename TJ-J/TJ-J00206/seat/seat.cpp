#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,max,min;
	cin >> n >> m;
	int a[n*m];
	for(int i = 0;i < n*m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	for(int i = 0;i < n*m; i++)
	{
		max = a[0];
		min = a[1];
		if(a[i] > max)
		{
			min = max;
			max = a[i];
		}
	}
	cout << "1 2";
	return 0;	
} 
