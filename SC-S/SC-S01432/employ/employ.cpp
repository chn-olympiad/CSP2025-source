#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
bool vis[505];
int ans = 0;
string s;
void dfs(int now,int fail,int g){
	if(now == n + 1){
		if(g >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		if(s[now - 1] == '0'||fail >= c[i]) dfs(now + 1,fail + 1,g);
		else dfs(now + 1,fail,g + 1);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	bool flag = true;
	for(int i = 0;i < s.size();i++){
		if(s[i] == '0') flag = false;
	}
	for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
	if(flag){
		ans = 1;
		for(int i = 1;i <= n;i++) ans *= i;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}