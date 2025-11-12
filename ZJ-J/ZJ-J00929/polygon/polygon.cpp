#include<bits/stdc++.h>
using namespace std;
int n,a[5005],c;
long long ans;

void dfs(int dep,int s,int m){
	if(dep>n) {
		cout<<s<<m<<'\n';
		if(s>m*2 && m>=3) ans++;
		return ;
	}	
	c++;
	dfs(dep+1,s+a[c],max(m,a[c]));
	dfs(dep+1,s+0,m+0);

}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
