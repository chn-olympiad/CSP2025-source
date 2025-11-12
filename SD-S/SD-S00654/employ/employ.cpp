#include<bits/stdc++.h>
using namespace std;

const int MAX=505;
const int mod=998244353;

int ans;
int n,m;
string s;
int c[MAX];

bool vis[MAX];
void dfs(int now,int mei)
{
	if(mei>n-m) return;
	if(now==n+1){
		ans++;
		ans=ans%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true) continue;
		vis[i]=true;
		if(s[now-1]=='0'||mei>=c[i]){
			dfs(now+1,mei+1);
		}
		else{
			dfs(now+1,mei);
		}
		vis[i]=false;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	memset(vis,false,sizeof(vis));
	dfs(1,0);
	cout<<ans%mod<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
