#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],ans=0,t=0,maxn=0;
string s;
bool vis[505];
void dfs(int x,int y,int z){
	if(y+m>n) return ;
	if(z>=m){
		int tot=1;
		for(int i=x;i<=n;i++) tot=tot*(i-x+1);
		ans+=tot;
		return ;
	}
	if(z<m&&y>maxn) return ;
	if(x>n){
		if(z>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x-1]=='0') dfs(x+1,y+1,z);
			else if(y>=c[i]) dfs(x+1,y+1,z);
			else dfs(x+1,y,z+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxn=max(maxn,c[i]);
		if(c[i]>0) t++; 
	}
	if(t<m){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
//那我还说啥了兄弟，直接挂了呗:(((((((((((((((((((((((
//四载光阴转瞬即逝，这是我最后一次了。
//就这样吧 
