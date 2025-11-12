#include<iostream>
using namespace std;
const int N=505;
int n,m,ans;
string s;
int c[N],p[N];
bool vis[N];
void dfs(int x,int fail){
	if(x==n+1){
		if(n-fail>=m)	ans++;
		return;
	}
	if(n-fail<m)	return;
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=true;
		if(s[x]=='0'||fail>=c[i])	dfs(x+1,fail+1);
		else	dfs(x+1,fail);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	if(n<=12){
		dfs(1,0);
		cout<<ans;
	}
	else	cout<<0;
	return 0;
}
