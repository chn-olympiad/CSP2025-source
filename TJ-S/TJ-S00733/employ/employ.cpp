#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;
const int N = 509;
int n,m,c[N],vis[N],ans;
string s;
int fa;

void dfs(int depth,int num)
{
	if(num >= m+1)
	{
		ans=(ans+1)%MOD;
	}
	if(depth == n+1) return;
	for(int i = 1 ;i <= n;++i)
	{
		if(!vis[i] && fa < c[i])
		{
			vis[i] = 1;
			if(s[depth-1] == '0')
			{
				++fa;
				dfs(depth+1,num);
				--fa;
			}
			else
			{
				dfs(depth+1,num+1);
			}
			vis[i] = 0;
		}
	}
}
void solve()
{
	cin >> n>>m >> s;
	for(int i = 1;i <= n;++i) cin >> c[i];
	dfs(1,1);
	cout << ans <<endl;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
