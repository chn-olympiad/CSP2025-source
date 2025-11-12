#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[1000005], dp[3][1000005], st[1000005];
bool b1[9], b2[9];
long long ans = -1;
long long dpx = 1;
int cf[9] = {256,128,64,32,16,8,4,2,1};
void start()
{
	for (int i = 1; i <= 9; i++)
	{
		b1[i] = 0;
		b2[i] = 0;
	}
}
void two1(int x)
{
	int k = 9;
	int t = x;
	while(t > 0)
	{
		b1[k] = t%2;
		t /= 2;
		k--;
	}
}
void two2(int x)
{
	int k = 9;
	int t = x;
	while(t > 0)
	{
		b2[k] = t%2;
		t /= 2;
		k--;
	}
}
int check()
{
	int x = 0;
	for (int i = 1; i <= 9; i++)
	{
		if(b1[i] != b2[i])
		{
			x += cf[i-1];
		}
	}
	//cout << x << endl;
	return x;
}
int now(int r)
{
	long long xiabiao = 1e9;
	for (int i = r; i <= dpx; i++)
	{
		//cout << dp[2][i] << endl;
		if (dp[2][st[i]])
		{
			xiabiao = min(xiabiao, dp[2][st[i]]);
		}
	}
	return xiabiao;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	//cout << cf[8] << " " << cf[9] << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		long long x = a[i];
		if (x == k)
		{
			dp[1][dpx] = i;
			dp[2][dpx] = i;
			st[i] = dpx;
			++dpx;
		}
		for(int j = i+1; j <= n; j++)
		{
			//cout << i << " " << j << " " << x << " " << ans << endl;
			start();
			two1(x);
			two2(a[j]);
			//for (int u = 1; u <= 9; u++) cout << b1[u];
			//cout << endl;
			//for (int u = 1; u <= 9; u++) cout << b2[u];
			//cout << endl << endl; 
			x = check();
			if (x == k)
			{
				dp[1][dpx] = i;
				dp[2][dpx] = j;
				if (!st[i]) st[i] = dpx;
				++dpx;
			}
		}
	}
	//for (int i = 1; i <= dpx; i++)
		//cout << dp[1][i] << " " << dp[2][i] << endl;
		//for (int i = 1; i <= dpx; i++)
		//cout << st[i] << " ";
		//cout << endl;
	int r = 1;
	while(r < 200005)
	{
	//	cout << r << endl;
		++ans;
		r = now(r)+1;
		
	}
	cout << ans;
	return 0;
}
