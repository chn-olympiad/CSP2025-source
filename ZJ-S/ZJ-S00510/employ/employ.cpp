#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505],ans;
bool vis[505];
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]||s[i-1]=='0'){
			cnt++;
			continue;
		}
	}
	if(n-cnt>=m)
		return 1;
	return 0;
}
void dfs(int k){
	if(k>n){
		if(check()) ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool ooo=0;
	for(int i=0;i<s.size();i++) if(s[i]=='1') ooo=1;
	if(ooo==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
}
