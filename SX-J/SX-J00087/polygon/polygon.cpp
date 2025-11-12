#include <bits/stdc++.h>
using namespace std;
int a[100],n,m;
int main()
{
	cin >> n >> m;
	for (int i = 0;i <=n*m-1;i++)
	{
		cin >> a[i];
	}
	int r = a[0];
    for (int i = 0;i <= n*m-1;i++)
    {
    	for (int j = 0;j <=n*m-1;j++)
    	{
    		if (a[j]<a[j+1])
    		{
    			int b = a[j];
    			a[j] = a[j+1];
    			a[j+1] = b;
			}
		}
	}
	for (int i = 0;i <=n*m-1;i++)
	{
		cout << a[i];
	}
	int s[10][10];
	int p = 0;
	for (int i = 1;i<=n;i++)
    {
		for (int j = 1;j <= m;j++)
		{
			if (i % 2 == 0);
			    s[i][j] = a[p];
            if (i % 2 == 1);
                s[i][m-j-1] = a[p];
            p++;
		}
	    p++;
	}
    for (int i = 0;i<=n-1;i++)
	{
		for (int j = 0;j <= m-1;j++)
		{
			cout << s[i][j] << endl;
		}
	}
    for (int i = 0;i<=n-1;i++)
	{
		for (int j = 0;j <= m-1;j++)
		{
			if (r == s[i][j])
			cout << i << " " << j;
			break;
		}
	}
}