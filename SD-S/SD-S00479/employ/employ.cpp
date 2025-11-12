#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=4e5+1000,M2=1e3+100;
lint n,m;
string s;
lint a[M1],b[M1];
bool f[M1];
bool o=1;
lint cnt;
void dfs(lint step)
{
	if(step==n+1)
	{
		lint op=0,sum=0;
		for(lint i=1;i<=n;i++)
		{
			lint oph=b[i];
			if(op>=a[oph])
			{
				op++;
				continue;
			}
			if(s[i-1]=='1') sum++;
			else op++;
		}
		if(sum>=m) cnt++;
	}
	for(lint i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			b[step]=i;
			f[i]=1;
			dfs(step+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(lint i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt<<"\n";
	return 0;
}
