#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll cnt = 0;
ll a[5200] = {};
ll b[5200] = {};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	ll maxn = 0;
	ll sum = 0;
	for(int i = 1; i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		sum += a[i];
	}
	if(sum > maxn * 2)
		cout << 1;
	else
		cout << 0;
	

//	for(int i = 1; i <= n;i++)
//	{
//		int x;
//		cin >> x;
//		a[i] = x;
//		b[i] = b[i-1] + x;
//	}
////	for(int i = 1; i <= n;i++)
////	{
////		cout << b[i] << ' ';
////	}
//	for(int i = 1; i <= n;i++)
//	{
//		for(int j = i; j <= n;j++)
//		{
//			ll maxn = 0;
//			for(int l = i;l <= j;l++)
//			{
//				maxn = max(maxn,a[i]);
//			}
//			ll sum = b[j]-b[i-1];
//			//cout << maxn << ' ' << sum << "   ";
//			if(j - i < 2)
//				continue;
//			if(sum > maxn * 2)
//				cnt++;
//		}
//	}
//	cout << cnt;
	return 0;
}
