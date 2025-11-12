#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n,m;
	int a1, s = 1;
	
	cin>>n>>m>>a1;
	for(int i = 2; i <= n * m; i++)
	{
		int x;
		cin>>x;
		if(x > a1)
		{
			s++;
		}
	}
	
	int l = (s + n - 1) / n, h;
	if(l % 2 == 1)
	{
		h = s % n;
		if(h == 0) h = n;
	}
	else
	{
		h = n + 1 - (s % n);
		if(h == n + 1) h == 1;
	}
	cout<<l<<" "<<h; 
	
	return 0;
}
