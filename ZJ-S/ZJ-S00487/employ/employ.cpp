#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[1000];
int f[1000];
int ans;
void dfs(int k,int p)
{
	if(k>n)
	{
		if(p>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])
		{
			f[i]=1;
			if(k-1-p>=c[i]||s[k-1]=='0') dfs(k+1,p);
			else dfs(k+1,p+1);
			f[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
