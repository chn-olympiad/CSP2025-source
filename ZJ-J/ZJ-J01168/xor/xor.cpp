#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 5e5 + 10;

int n, flag;
LL k, ans, a[N], sum[N], vis[N];

vector<PII> v;

bool cmp(PII A, PII B)
{
	return A.second - A.first < B.second - B.first;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) flag = 1;
		sum[i] = sum[i - 1] ^ a[i];
	}
	
	
	if(flag == 0 && k == 0)//A
	{
		cout << n / 2 << "\n";
		return 0;
	}
	flag = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!(a[i] == 0 || a[i] == 1))
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 0 && k <= 1)//B
	{
		if(k == 1)
		{
			LL cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 1)
				{
					cnt++;
				}
			}
			cout << cnt << "\n";
		}
		else
		{
			LL cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 0)
				{
					cnt++;
				}
			}
			
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 1 && a[i + 1] == 1)
				{
					cnt++;
					i++;
				}
			}
			
			cout << cnt << "\n";
		}
		return 0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if((sum[j] ^ sum[i - 1]) == k)
			{
				v.push_back({i, j});
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto it : v)
	{
		int l = it.first, r = it.second;
		flag = 0;
		for(int i = l; i <= r; i++)
		{
			if(vis[i] == 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1) continue;
		
		ans++;
//		cout << l << " " << r << "\n";
		for(int i = l; i <= r; i++)
		{
			vis[i] = 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
/*
1048576
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
