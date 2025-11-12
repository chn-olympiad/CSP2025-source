#include <bits/stdc++.h>
using namespace std; 
int n,m,a[105],c = 1,r = 1;
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n * m;i++)
	{
	    if (a[1] > a[i])
	    {
	    	r++;
		}
	}
	cout << c << " " << r;
	return 0;
}
