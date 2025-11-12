#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int a[5005];
long long int f[5005];
long long int sum;
long long int ans;
long long int mmax = INT_MIN;
void yunsuan(long long int Max)
{
	if (sum > 2 * Max)
	{
		ans ++;
		ans = ans % 998244353;
	}
}
void dfs(long long int step,long long int Max)
{
	if (step > n)
	{
		yunsuan(Max);
		return ;
	}
	sum += a[step];
	dfs(step + 1,max(Max,a[step]));
	sum -= a[step];
	dfs(step + 1,Max);
}
void dfs22(long long int step,long long int Max)
{
	if (sum > 200)
	{
		ans ++;
		ans = ans % 998244353;
		return ;
	}
	if (step > n)
	{
		yunsuan(Max);
		return ;
	}
	sum += a[step];
	dfs(step + 1,max(Max,a[step]));
	sum -= a[step];
	dfs(step + 1,Max);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		mmax = max(mmax,a[i]);
	}
	if (mmax == 1)
	{
		long long int ss = n * (n - 1) % 998244353;
		long long int ss1 = 1 * 2;
		for (long long int i = 3;i <= n;i ++)
		{
			ss1 = ss1 * i % 998244353;
			ss = ss * (n - i + 1) % 998244353;
			ans += ss / ss1;
//			cout << ss1 << " " << ss << endl;
//			cout << ans << endl;
			ans %= 998244353;
		}
		cout << ans;
	}
	else if (n <= 20)
	{
		dfs(1,INT_MIN);
		cout << ans - 1;//mAX = INT_MIN
	}
	else
	{
		dfs22(1,INT_MIN);
		cout << ans - 1;//mAX = INT_MIN
	}
}
