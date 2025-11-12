#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int mod=998244353;
int c[N],n,m,ans=0;
bool vis[15],s[N];
int a[15];
void dfs(int nw){
	if(nw==n+1){
		int cnt=0;
		for(int i=1;i<=n;++i)if(s[i]==0||cnt>=c[a[i]])cnt++;
		if(n-cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		a[nw]=i;
		vis[i]=true;
		dfs(nw+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string ss;
	cin>>ss;
	ss=" "+ss;
	bool bj1=true;
	for(int i=1;i<=n;++i){
		s[i]=ss[i]-'0';
		if(!s[i])bj1=false;
	}
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
