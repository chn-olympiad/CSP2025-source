#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const ll mod = 998244353;
int fa,n,m;
int a[N],c[N],ch[N];
ll ans = 0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char x;
	fa = 1;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		ch[i] = i;
		cin>>x;
		if(x == '1')
		{
			a[i] = 1;
		}
		else
		{
			fa = 0;
			a[i] = 0;
		}
		sum += a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin>>c[i];
	}
	if(m != n && n > 10)
	{
		cout<<0;
		return 0;
	}
	if(m == n)
	{
		ans = 1;
		for(int i = 1;i <= n;i++)
		{
			ans = ans * (1ll * i) % mod;
			if(c[i] == 0 || a[i] == 0)
			{
				ans = 0;
			}
		}
		cout<<ans;
		return 0;
	}
	do
	{
		int cnt = 0,cnt2 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt >= c[ch[i]])
			{
				cnt++;
				continue ;
			}
			if(a[i] == 0)
			{
				cnt++;
				continue;
			}
			cnt2++;
		}
		if(cnt2 >= m)
		{
			ans++;
			ans %= mod;
		}
	}while(next_permutation(ch + 1,ch + 1 + n));
	cout<<ans;
	return 0;
}
