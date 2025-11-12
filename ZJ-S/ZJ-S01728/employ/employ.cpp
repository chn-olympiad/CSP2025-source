#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int MOD=998244353;
int sum[N],ans,answer,n,m,x,v[N],a[N];
string s;
void dfs(int step,int tao)
{
	if(n-(tao+(sum[n]-sum[step-1]))<m) return ;
	if(step>n)
	{
		if(n-tao>=m) answer++;
		answer%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0) 
		{
			x=0;
			v[i]=1;
			if(s[step]=='0') x++;
			else if(tao>=a[i]) x++;
			dfs(step+1,tao+x);
			v[i]=0;
		}
	}
}
int main()
{
  	freopen("employ.in","r",stdin);
  	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='0');
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<answer;
	return 0;
}
