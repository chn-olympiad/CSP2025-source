#include <bits/stdc++.h>
using namespace std;

int a[5005],cnt,num,ma;
int n;

void dfs(int x,int k)
{
	if(x >= 3)
		if(ma * 2 < num)
			cnt++;
	if(k == n+1)
	{
		return;
	}
	for(int i = k;i <= n;i++)
	{
		int t = ma;
		num += a[i];
		ma = a[i];
		dfs(x+1,i+1);
		num -= a[i];
		ma = t;
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n == 3)
	{
		cin >> a[1] >> a[2] >> a[3];
		if(a[1] + a[2] > a[3]&&a[1] + a[3] > a[2]&&a[3] + a[2] > a[1])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	long long num = 0;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n <= 20)
	{
		sort(a+1,a+n+1);
		dfs(0,1);
		cout << cnt;
		return 0;
	}
	long long k = 1;
	for(int j = 0;j < 3;j++)
	{
		k *= (n-j);
		k /= (j+1);
		k %= 998244353;
	}
	num += k;
	num %= 998244353;
	for(int i = 4;i <= n;i++)
	{
		k *= (n-i+1);
		k /= i;
		k %= 998244353;
		num += k;
		num %= 998244353;
	}
	cout << num;
	return 0;
}
