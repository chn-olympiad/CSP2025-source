#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int n,m,c[505],ans=0,sum[505],id[505];
void dfs(int x,int y,int z)
{
	if(x==n+1)
	{
		if(z>=m) ans++,ans%=mod;
		return;
	}
	if(sum[x]+z<m) return;
	if(c[id[x]]<=y) dfs(x+1,y+1,z);
	else if(s[x-1]=='1') dfs(x+1,y,z+1);
	else dfs(x+1,y+1,z);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i],id[i]=i;
	for(int i=n;i>=1;i--) sum[i]=sum[i+1]+(s[i-1]-'0');
	do
	{
		dfs(1,0,0);
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<endl;
	return 0;
}
