#include<bits/stdc++.h>
using namespace std;
template < typename T > void read(T &Read_)
{
	Read_ = 0; char c = getchar(); bool sgn = 0;
	while(!isdigit(c)) { sgn |= (c == '-'); c = getchar(); }
	Read_ = c - '0'; c = getchar();
	while(isdigit(c)) { Read_ = (Read_ << 1) + (Read_ << 3) + c - '0'; c = getchar(); }
	if(sgn) { Read_ = -Read_; }
}
template < typename T > void print(T Print_)
{
	char st[30]; int top = 0;
	if(Print_ < 0) { putchar('-'); Print_ = -Print_; }
	do { st[++top] = Print_ % 10; Print_ /= 10; } while(Print_);
	while(top) { putchar(st[top--] + '0'); }
}
int n , m;
int num[25];
long long dp[(1 << 18)][20];
bool s[25];
const long long mod = 998244353;
int popc(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt += x % 2;
		x /= 2;
	}
	return cnt;
}
int main()
{
	// D employ
	// 注意 m = n 时需要判断 
	// 打的状压 DP 
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	read(n);
	read(m);
	if(n == m)
	{
		bool y = 1;
		for(int i = 1 ; i <= n ; i++)
		{
			char c;
			cin >> c;
			y &= (c == '1');
		}
		for(int i = 1 ; i <= n ; i++)
		{
			int c;
			read(c);
			y &= (c != 0);
		}
		long long fac = 1;
		for(int i = 1 ; i <= n ; i++)
		{
			fac *= i;
			fac %= mod;
		}
		if(y)
		{
			print(fac);
		}
		else
		{
			print(0);
		}
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		char c;
		cin >> c;
		s[i] = (c == '1');
	}
	for(int i = 1 ; i <= n ; i++)
	{
		read(num[i]);
	}
	dp[0][0] = 1;
	for(int S = 1 ; S < (1 << n) ; S++)
	{
		int nxti = popc(S);
		for(int i = 1 ; i <= n ; i++)
		{
			if((S >> (i - 1)) & 1)
			{
				int preS = S - (1 << (i - 1));
				for(int bef = 0 ; bef <= n ; bef++)
				{
					if(bef >= num[i])
					{
						dp[S][bef + 1] += dp[preS][bef];
						dp[S][bef + 1] %= mod;
						continue;
					}
					dp[S][bef + !s[nxti]] += dp[preS][bef];
					dp[S][bef + !s[nxti]] %= mod;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0 ; i <= n - m ; i++)
	{
		ans += dp[(1 << n) - 1][i];
		ans %= mod;
	}
	print(ans);
	return 0;
}
/*
zip password Ren5Jie4Di4Ling5% 
提交要求 
1. 在 D 盘根目录下创建文件夹 SD-S00001张三（准考证号 + 名字，中间无空格，注意是英文短杠） 
2. 下面放题目文件夹 
3. 题目文件夹只放对应题目的源程序 
*/
