#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10,mod=998244353;
int n,m,c[maxn],timer[maxn],ans,peo[maxn];
string s;
void dfs(int depth)
{
	if(depth>n)
	{
		int x=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[peo[i]])cnt++;
			else if(s[i-1]=='1')x++;
			else if(s[i-1]=='0')cnt++;
//			cout<<peo[i]<<' '<<x<<' '<<cnt<<endl;
		}
//		cout<<endl<<cnt<<' '<<x<<endl;
		if(x>=m)ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)if(!timer[i])
		{
			timer[i]=depth;
			peo[depth]=i;
			dfs(depth+1);
			timer[i]=0;
			peo[depth]=0;
		}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
