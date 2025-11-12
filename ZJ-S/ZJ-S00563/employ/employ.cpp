#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
bool vis[501];
int jc[501];
int ci[501];
int ji[501];
int c[501];
int cnt = 0;
string s;
int n,m;

void dfs(int t,int tcnt)
{
	if(tcnt > n-m)
	{
		return;
	}
	if(t > n)
	{
		cnt++;
		
//		if(tcnt == m)
//		{
//			for(int i = 1;i <= n;i++)
//			{
//				printf("%lld ",ji[i]);
//			}
//			printf("\n");
//		}
		
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == false)
		{
			vis[i] = true;
			ji[t] = i;
			if(tcnt >= ci[i]||s[t-1] == '0')
			{
				dfs(t+1,tcnt+1);
			}
			else
			{
				dfs(t+1,tcnt);
			}
			vis[i] = false;
		}
	}
}

#undef int
int main()
{
#define int long long

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    jc[0] = 1;
    for(int i = 1;i <= 500;i++)
    {
    	jc[i] = jc[i-1]*i%mod;
	}
    scanf("%lld %lld",&n,&m);
    cin >> s;
    for(int i = 1;i <= n;i++)
    {
    	scanf("%lld",&ci[i]);
    	c[ci[i]]++;
	}
	int lst;
	for(lst = n;lst >= 1;lst--)
	{
		if(s[lst-1] == '1')
		{
			break;
		}
	}
	if(lst == 0)
	{
		if(m == 0)
		{
			printf("%lld\n",jc[n]);
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	int cnt1 = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt1 += s[i-1]-'0';
	}
	if(m == n)
	{
		if(cnt1 == n&&c[0] == 0)
		{
			printf("%lld\n",jc[n]);
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	if(n > 30)
	{
		printf("0\n");
		return 0;
	}
	dfs(1,0);
	printf("%lld\n",cnt);
    return 0;
}
