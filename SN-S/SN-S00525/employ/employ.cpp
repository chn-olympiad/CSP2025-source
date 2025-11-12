#include<bits/stdc++.h>
using namespace std;
int n,m,fal=0,win=0,ans=0;
int c[505],d[505];
void dfs(int x) {
	if(win==m){
		ans++;
		return;
	}
		else {
			if(fal<c[x]) {
				win++;
				dfs(c[x+1]);
			} else {
				fal++;
				dfs(c[x+1]);
			}
		}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int s;
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
    dfs(c[1]);
	ans=ans%998244353;
    cout<<ans;
	return 0;
}
