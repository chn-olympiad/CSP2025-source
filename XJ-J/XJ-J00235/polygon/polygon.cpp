#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[5010];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n;i++)
	{
		if(a[i] < a[i-1] + a[i-2] || a[i-1] < a[i] + a[i-2] || a[i-2] < a[i-1] + a[i])
			cnt++;
	}
	cout << 998244353%cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
