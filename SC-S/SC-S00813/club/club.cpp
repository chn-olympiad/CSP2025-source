#include <bits/stdc++.h>
using namespace std;
#define int long long
struct stu
{
	int a,b,c;
} school[100005];
int a = 0,b = 0,c = 0,ans = 0;
bool cmp(stu x,stu y)
{
	return max(x.a,max(x.b,x.c)) > max(y.a,max(y.b,y.c));
}
bool cmp1(stu x,stu y)
{
	return x.a > y.a;
}
bool cmp2(stu x,stu y)
{
	return x.a - x.b > y.a - y.b;
}
void join(int add,int cls)
{
	if(cls == 0)
	{
		a++;
		ans += school[add].a;
	}
	if(cls == 1)
	{
		b++;
		ans += school[add].b;
	}
	if(cls == 2)
	{
		c++;
		ans += school[add].c;
	}
	return;
}
int dp[205][105][105][3];
void dp_p(int n)
{
	int ans = 0;
	for(int i = 1;i <= n;i++) cin >> school[i].a >> school[i].b >> school[i].c;
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= (n >> 1);j++)
		{
			for(int k = 0;k <= (n >> 1);k++)
			{
				int l = i - j - k;
				if(l < 0 || l > (n >> 1)) continue;
				if(j > 0)
				{
					dp[i][j][k][0] = max(dp[i][j][k][0],dp[i - 1][j - 1][k][0] + school[i].a);
					dp[i][j][k][0] = max(dp[i][j][k][0],dp[i - 1][j - 1][k][1] + school[i].a);
					dp[i][j][k][0] = max(dp[i][j][k][0],dp[i - 1][j - 1][k][2] + school[i].a);
				}
				if(k > 0)
				{
					dp[i][j][k][1] = max(dp[i][j][k][1],dp[i - 1][j][k - 1][0] + school[i].b);
					dp[i][j][k][1] = max(dp[i][j][k][1],dp[i - 1][j][k - 1][1] + school[i].b);
					dp[i][j][k][1] = max(dp[i][j][k][1],dp[i - 1][j][k - 1][2] + school[i].b);
				}
				if(l > 0)
				{
					dp[i][j][k][2] = max(dp[i][j][k][2],dp[i - 1][j][k][0] + school[i].c);
					dp[i][j][k][2] = max(dp[i][j][k][2],dp[i - 1][j][k][1] + school[i].c);
					dp[i][j][k][2] = max(dp[i][j][k][2],dp[i - 1][j][k][2] + school[i].c);
				}
				ans = max(max(ans,dp[i][j][k][2]),max(dp[i][j][k][0],dp[i][j][k][1]));
			}
		}
	}
	cout << ans << endl;
}
void sol(int n)
{
	int ans = 0;
	sort(school + 1,school + n + 1,cmp1);
	for(int i = 1;i <= (n >> 1);i++) ans += school[i].a;
	cout << ans << endl;
	return;
}
void sol2(int n)
{
	int ans = 0;
	sort(school + 1,school + n + 1,cmp2);
	for(int i = 1;i <= (n >> 1);i++) ans += school[i].a;
	for(int i = (n >> 1) + 1;i <= n;i++) ans += school[i].b;
	cout << ans << endl;
	return;
}
void pcs()
{
	a = b = c = ans = 0;
	int n;
	cin >> n;
	if(n <= 200)
	{
		dp_p(n);
		return;
	}
	int pat = ((n + 1) / 2);
	int _2 = 0,_3 = 0; 
	for(int i = 1;i <= n;i++)
	{
		cin >> school[i].a >> school[i].b >> school[i].c;
		_2 |= school[i].b;
		_3 |= school[i].c;
	}
	if(_2 == 0 && _3 == 0)
	{
		sol(n);
		return;
	}
	else if(_3 == 0)
	{
		sol2(n);
		return;
	}
	sort(school + 1,school + n + 1,cmp);
	for(int i = 1;i <= n;i++)
	{
		//cout << school[i].a << " " << school[i].b << " " << school[i].c << endl;
		if(school[i].a > school[i].b && school[i].a > school[i].c)
		{
			if(a < pat) join(i,0);
			else
			{
				if(school[i].b > school[i].c) join(i,1);
				else join(i,2);
			}
		}
		else if(school[i].b > school[i].a && school[i].b > school[i].c)
		{
			if(b < pat) join(i,1);
			else
			{
				if(school[i].a > school[i].c) join(i,0);
				else join(i,2);
			}
		}
		else
		{
			if(c < pat) join(i,2);
			else
			{
				if(school[i].a > school[i].b) join(i,0);
				else join(i,1);
			}
		}
	}
	cout << ans << endl;
	ans = 0;
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) pcs();
	return 0;
}