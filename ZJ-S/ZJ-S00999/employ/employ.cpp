#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],c[15],s[15],n,m,ans;
void dfs(int dep){
	if(dep>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i-cnt-1>=c[a[i]])continue;
			if(s[i])cnt++;
		}
		if(cnt>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		a[dep]=i,b[i]=1;
		dfs(dep+1);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}