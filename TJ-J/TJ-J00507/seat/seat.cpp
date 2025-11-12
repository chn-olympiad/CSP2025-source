#include<bits/stdc++.h>
using namespace std;

int n,m,a[101];
int c;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	c = a[1];
	//cout << c << endl;
	//for(int i = 1;i <= n*m;i++) cout << a[i] << " ";
	//cout << endl;
	sort(a+1,a+n*m+1,greater<int>());
	//for(int i = 1;i <= n*m;i++) cout << a[i] << " ";
	//cout << endl;
	for(int i = 1;i <= n*m;i++)
	{
		if(c == a[i])
		{
			c = i;
			break;
		}
	}
	//cout << c << endl;
	cout << (c - 1)/n+1 << " ";
	if(((c - 1)/n+1) % 2 == 1)
	{
		if(c % n ==0)
		{
			cout << n;
			return 0; 
		}
		cout << c%n;
	}
	else
	{
		if(c%n==0)
		{
			cout << 1;
			return 0;
		 } 
		cout << n - c%n + 1;	
	}
	return 0;
}
