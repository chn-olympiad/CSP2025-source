#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	ll a[n+1][m+1];
	ll b[n*m+1];
	ll cnt = 1;
	for(ll i = 1;i <= n;i++)
		for(ll j = 1;j <= m;j++)
		{
			cin >> a[i][j];
			b[cnt] = a[i][j];
			cnt++;
		}
	for(int i = 1;i < cnt;i++)
	{
		for(int j = 1;j < cnt - 1;j++)
		{
			if(b[j]<b[j+1])
			{
				ll hu = b[j];
				b[j] = b[j+1];
				b[j+1] = hu;
			}
		}
	}
	ll ming = a[1][1];
	ll f;
	for(ll i = 1;i < cnt;i++)
	{
		if(b[i]==ming)
			f = i;
	}
	int sum = 1;
	bool flag = 1;
	for(int i = 1;i <= m;i++)
	{
		if(flag==0)
		break;
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				if(f == sum)
				{
					flag = 0;
					cout << i << " " << j;
				}
				sum += 1;
			}
		}
		else
		{
				for(int j = n;j >= 1;j--)
				{
					if(f == sum)
					{
						flag = 0;
						cout << i << " " << j;
					}
					sum += 1;
				}
		}
	}
	return 0;
}
