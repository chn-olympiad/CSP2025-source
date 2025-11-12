#include<bits/stdc++.h>
using namespace std;
int a[5005];
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	} 
	sort(a,a+n+1,cmp);
	if (n < 3)
	{
		cout << "0";
		return 0; 
	}
	if (n == 3)
	{
		if (a[1]+a[2]>a[3])
		{
			cout << 1;
			return 0;
		}
		cout << 0;
	}
	
	int cnt=0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
