#include<bits/stdc++.h>
using namespace std;
char c[20];
int t[20];
int n,m,p[20],v[20],ans=0;
void dfs(int u){
	if(u==n+1){
		int rej=0;
		for(int ii=1;ii<=n;ii++){
			int i=p[ii];
			if(rej>=t[i])rej++;
			else{
				if(c[ii]!='1')rej++;
			}
		}
		if(n-rej>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		p[u]=i;
		dfs(u+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	if(n>18)return 0;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>t[i];
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}