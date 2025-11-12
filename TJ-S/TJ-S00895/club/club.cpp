#include <bits/stdc++.h>

using namespace std;

int x[100001][100001],y[100001][100001],z[100001][100001];
int main()
{
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	int t,n,a,b,c; 
	cin >> t >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i][1];
		cin >> y[i][2];
		cin >> z[i][3];
		if(x[i][1] >= 0)
		{
			a += x[i][1];
			a += 1;
		}
		else
		{
			b += y[i][2];
			b += 1;
		}
		else
		{
			c += z[i][3];
			c += 1;
		}
	}
	cout << a << endl << b << endl << c << endl;
	return 0;
} 
