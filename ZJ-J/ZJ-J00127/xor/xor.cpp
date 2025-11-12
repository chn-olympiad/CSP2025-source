#include<bits/stdc++.h>
using namespace std;

int a[500005];
int d1g[21],d2g[21];

int xor_1(int x)
{
	for(int i = 0;i <= 20;i++)
	{
		d1g[i] = 0;
	}
	int now = 20;
	while(x)
	{
		d1g[now--] = x % 2;
		x /= 2;
	}
	return now;
}

int xor_2(int x)
{
	for(int i = 0;i <= 20;i++)
	{
		d2g[i] = 0;
	}
	int now = 20;
	while(x)
	{
		d2g[now--] = x % 2;
		x /= 2;
	}
	return now;
}

int xorsum(int now1,int now2)
{
	int sum = 0;
	for(int i = min(now1,now2);i <= 20;i++)
	{
		sum *= 2;
		if(d1g[i] != d2g[i])
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
//	for(int i = 1;i <= n;i++)
//	{
//		cout << b[i] << ' ';
//	}
	//abs()
	//abs(a[r] - a[l])
	int cnt = 0;
	int l = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = l;j <= i;j++)
		{
			int sum = a[j];
			for(int now = j + 1;now <= i;now++)
			{
				sum = xorsum(xor_1(sum),xor_2(a[now]));
			}
			if(sum == k)
			{
				cnt++;
				l = i + 1;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}