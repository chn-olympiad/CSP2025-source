#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,c[505],f[505],ans;
bool flag[505];
int P[505];
string S;
void dfs(int x,int s)
{
	if(x-1-s>=m){ans=(ans+f[n-x+1])%p;return ;}
	if(x>n)return ;
	for(int i=1;i<=n;i++)if(!flag[i])
	{
		flag[i]=true;P[x]=i;
		dfs(x+1,s+(S[x]=='0'||s>=c[i]));
		flag[i]=false;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>S;S=' '+S;f[0]=1;
	for(int i=1;i<=n;i++){cin>>c[i];f[i]=f[i-1]*i%p;}
	if(m==n)
	{
		for(int i=1;i<=n;i++)if(S[i]=='0'){cout<<"0";return 0;}
		cout<<f[n];return 0;
	}
	dfs(1,0);cout<<ans;
	return 0;
}
//12pts TLE
