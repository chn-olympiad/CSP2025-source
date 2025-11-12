#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[510],c[510],p;
long long ans;
char s[510];
bool flag[510];
void dfs(int x)
{
	if(x>n)
	{
		p=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') p++;
			else
				if(p>=c[a[i]])
					p++;
		}
		if(n-p==m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==1) continue;
		flag[i]=1;
		a[x]=i;
		dfs(x+1);
		flag[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
