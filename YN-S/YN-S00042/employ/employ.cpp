#include<iostream>
using namespace std;
#define mo 998244353
int n,m,st[25],yes[25],s[25],ans;
void dfs(int u,int x){
	if(u>n){
		if(x>=m)ans=(ans+1)%mo;
		return;
	}for(int i=1;i<=n;i++){
		if(!st[i]){st[i]=1;
			if(u-x-1>=s[i]||!yes[u])dfs(u+1,x);
			else dfs(u+1,x+1);
			st[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c=getchar();
	for(int i=1;i<=n;i++)c=getchar(),yes[i]=c^48;
	for(int i=1;i<=n;i++)cin>>s[i];
	dfs(1,0);cout<<ans;return 0;
}