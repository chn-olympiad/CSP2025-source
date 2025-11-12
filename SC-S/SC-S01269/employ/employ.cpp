#include <bits/stdc++.h>
using namespace std;
char c[505];
const int MOD = 998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool flag1 = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if(c[i] == 0)
		{
			flag1 = 1;
		}
	}
	if(flag1 == 0)
	{
		long long ans = 1,y = n,cur = 0;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if(x <= cur)
			{
				y--;
				cur++;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			ans = ans * i % MOD;
		}
		cout << ans << endl;
	}
    return 0;
}