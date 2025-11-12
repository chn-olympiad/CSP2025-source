#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[200];
	cin>>n>>m;
	for(int i = 1; i <= n* m; i++)
		cin>>a[i];
	int id = a[1],sum;
	sort(a+1,a+1+(n*m),greater<int>());
	for(int i = 1; i <= n*m;i++)
	{
		if(a[i] == id)
		{
			sum = i;
			break;
		}
	}
	int x, y, z;
	x = (int)ceil(sum*1.0/m);
	z = sum % m;
	if(x % 2 == 1)
	{
		int op = sum - (x - 1)*m;
		y = op;
	}
	else
	{
		int op = sum - (x - 1)*m;
		y = m - op + 1;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
