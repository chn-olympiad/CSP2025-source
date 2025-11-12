#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int n,m,a[103],x;
	cin >> n >> m;
	for (int i = i;i <= n*m;i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort(a+1,a+n+1);
	int y = x/m,z;
	int h = x % n;
	if (x % m == 0)
	{
		cout << x/m<<" ";
		cout << n;
	}
	else
	{
		cout << y+1 << " ";
		if(y % 2 == 0)
		{
			cout << n - h;
		}
		else
		{
			cout << h;
		}
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
