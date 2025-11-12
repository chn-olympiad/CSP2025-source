#include<bits/stdc++.h>
using namespace std;
int a[505],b[505],vis[505],c[505],n,m,ans;
string s;
void fun(){
	int num=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(num>=c[b[i]]){
			num++;
			continue;
		}
		if(a[i]==1) num++;
		else cnt++;
		//cout<<num<<' '<<cnt<<'\n';
	}
	ans+=(cnt>=m);
	//cout<<(cnt>=m)<<' ';
}
void dfs(int x){
	if(x>n){
		fun();
		//for(int i=1;i<=n;i++) cout<<b[i]<<' ';
		//cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		b[x]=0;
		vis[i]=0;
	}
}
signed main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') a[i+1]=0;
		else a[i+1]=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
