#include<bits/stdc++.h>
using namespace std;
string s;
bool vis[505];
int n,m,ans,c[505],p[505];
bool dfs(int i,int passed) {
	if(i>n) {
		if(passed>=m) {
			return 1;
		}
		return 0;
	}
	if(s[p[i]-1]&&passed<c[p[i]]) {
		return dfs(i+1,passed);
	}
	return dfs(i+1,passed+1);
}
void f(int i) {
	if(i==n) {
		if(dfs(1,0)) {
			ans++;
		}
		return;
	}
	for(int j=1; j<=n; j++) {
		if(!vis[j]) {
			vis[j]=1;
			p[i+1]=j;
			f(i+1);
			vis[j]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	f(0);
	cout<<ans;
	return 0;
}