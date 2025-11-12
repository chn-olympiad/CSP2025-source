#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1008617],ans;
string s;
int pailie[1008617];
bool used[1008617];
void dfs(int now)
{
	if(now>n)
	{
		int tt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||tt>=a[pailie[i]])tt++;
		}
		if(n-tt>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i])continue;
		used[i]=true;
		pailie[now]=i;
		dfs(now+1);
		used[i]=false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(used,false,sizeof(used));
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1);
    cout<<ans;
	return 0;
}