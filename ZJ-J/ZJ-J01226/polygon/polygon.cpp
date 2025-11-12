#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
void dfs(int x,int y,int z) {
	if(x>n) {
		if(y>2*z) {
			ans++;
		}
		return ;
	}
	dfs(x+1,y+a[x],max(z,a[x]));
	dfs(x+1,y,z);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;

	return 0;
}