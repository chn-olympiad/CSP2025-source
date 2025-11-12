#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

//写个注释证明我是自己写的 >:)



int jc(int x)
{
	return (x * (jc(x) % 998244353)) % 998244353;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,people[510],lost[510]= {0};

	string diff;
	
	cin >> n >> m;
	
	cin >> diff;
	int zero_p = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> people[i];
		if (people[i] == 0)
		{
			zero_p = 0;
		}
	}
	for (int i = 0; i < diff.size(); i++)
	{
		if (diff[i] == '0')
		{
			lost[i + 1] = lost[i] + 1;
		}
		else
		{
			lost[i + 1] = lost[i];
		}
	}
	
	if (lost[n] == 0)
	{
		cout << jc(n);
		return 0;
	}
} 
