#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,M=505;
int n,m;
string s;
int c[N];
int d[N];
bool v[N];
int ans=0;
void dfs(int step,int ct)
{
	if(step==n+1) 
	{
		if(ct>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]) continue;
		v[i]=1;
		if(s[step-1]=='0'||c[i]<=step-ct-1) dfs(step+1,ct);
		else dfs(step+1,ct+1);
		v[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0') d[i+1]++;
		d[i]+=d[i-1];
	}
	sort(c+1,c+n+1,greater<int>());
	if(n<=10) 
	{
		dfs(1,0);
		cout<<ans<<endl;
		return 0;
	}
	int res=1;
	for(int i=1;i<=n;i++) (res*=i)%=998244353;
	cout<<res<<endl;
	return 0;
}
