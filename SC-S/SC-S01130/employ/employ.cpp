#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[501],vis[501],box[501];
long long cnt;
void solve(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(box[i]<=cnt2){
			cnt2++;
		}else{
			if(s[i]=='1'){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		
		if(cnt1>=m){
			cnt=(cnt+1)%998244353;
			return;
		}
	}
}
void dfs(int x){
	if(x==n+1){	
		solve();
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				box[x]=a[i];
				dfs(x+1);
				vis[i]=0;
			} 
		}
	}
}
int main(){
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=false;
		}
	}
	if(flag){
		long long ans=1;
		while(m--){
			ans=(ans*n)%998244353;
			n--;
		}
		cout<<ans;
		return 0;
	}
	s=" "+s;
	dfs(1);
	cout<<cnt;
	return 0;
}