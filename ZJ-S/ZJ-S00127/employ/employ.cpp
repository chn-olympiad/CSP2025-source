#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int pa[505];
int mod=998244353;
int ans;
int vis[505];
int order[505];
bool judge(){
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')return false;
	}
	return true;
}
void dfs(int deep,int cnt,int num){
	if(deep==n+1){
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			order[deep]=i;
			if(num>=pa[i]||s[i-1]=='0'){
				dfs(deep+1,cnt,num+1);
			}
			else if(s[i-1]=='1'){
				dfs(deep+1,cnt+1,num);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>pa[i];
	if(judge()){
		long long ans=1;
		int cnt=0;
		for(int i=1;i<=n;i++)if(pa[i]!=0)cnt++;
		for(int i=1;i<=cnt;i++){
			ans%=mod;
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10){
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
