#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,mod=998244353;
bool vis[maxn];
int n,m,res=0;
char s[maxn];
int a[maxn],b[maxn];
void dfs(int now,int num)
{
	if(now>n&&n-num>=m)
	{
		res++;
		res%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			vis[i]=0;
			if(b[now]==0||num>=a[i])
			{
				dfs(now+1,num+1);
			}
			else
			{
				dfs(now+1,num);
			}
			vis[i]=1;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=s[i-1]-'0';
		vis[i]=1;
	}
	dfs(1,0);
	cout << res << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
