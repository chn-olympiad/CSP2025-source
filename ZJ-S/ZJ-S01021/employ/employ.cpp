#include<bits/stdc++.h>
using namespace std;

const int N=510;
int n,p,ans;
string s;
int a[N];
int b[N];
int vis[N];

void dfs(int x,int y){
	if(y>n-p)return;
	if(x==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		if(a[x]==0||a[x]==1&&y>=b[i])
			dfs(x+1,y+1);
		else dfs(x+1,y);
		vis[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>p>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)
		cin>>b[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}

