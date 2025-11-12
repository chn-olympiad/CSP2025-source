#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
int a[105],b[105];
bool vis[105];
const int P=998244353;
void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||sum>=a[b[i]]){
				sum++;
			}
		}
		if(n-sum>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
			b[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='0'+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else{
		bool fl=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				fl=0;
				break;
			}
			if(s[i]=='0'){
				fl=0;
				break;
			}
		}
		if(fl==0){
			cout<<0;
		}
		else{
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=P;
			}
			cout<<ans;
		}
	}
	return 0;
}
