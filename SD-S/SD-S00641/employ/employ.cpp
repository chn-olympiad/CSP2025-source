#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[1000],ans;
char s[1000];
bool vis[1000];
void dfs(int x,int y,int z){
	if(x>=n){
		if(y>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			if(s[i]=='0'||z>=c[i])
				dfs(x+1,y,z+1);
			else
				dfs(x+1,y+1,z);
		}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld\n",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%c",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
