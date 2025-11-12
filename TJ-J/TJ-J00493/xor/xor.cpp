#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
int a[100010];
int b[100010];
ll cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}
	for(int i = 1; i <= n;i++)
	{
		for(int j = i; j <= n;j++)
		{
			ll sum = b[i] ^ b[i-1];
			if(sum == k)
			{
				cnt++;
				i = j+1;
			}
		}
	}
	cout << cnt;
	return 0;
}
