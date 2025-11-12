#include<bits/stdc++.h>
using namespace std;
string s;
int n,c[1005],vis[1005],m,b[1005],ans=0,flag=1,cnt=0;
long long MOD=998244353;
void dfs(int p){
	if(p==n+1){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&b[i]>cnt2){
				cnt1++;
			}
			else cnt2++;
		}
		if(cnt1>=m) {
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		b[p]=c[i];
		vis[i]=1;
		dfs(p+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
