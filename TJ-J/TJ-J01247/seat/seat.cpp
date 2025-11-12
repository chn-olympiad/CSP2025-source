#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m; 
	cin >> a[1];
	int r = a[1]; 
	int cnt = 1;
	for(int i = 2;i <= n*m;i++)
	{
		cin >> a[i];
		if(a[i] > r) cnt++;
	}
	int x = cnt%n,y = cnt/n;
	if(x == 0) 
	{
		cout << y << " ";
		if(y%2==0) cout << 1;
		else cout << n;
	}
	else
	{
		y+=1;
		cout << y << " ";
		if(y%2==0) cout << n+1-x;
		else cout << x;
	}
	return 0;
 } 
