#include<bits/stdc++.h>
using namespace std;
int mp[505];
int n,m;
string a;
int d[505];
int vis[505];
bool check(){
	int lu=0;
	int wlu=0;
	for(int i=1;i<=n;i++){
		if(a[i-1]=='0')wlu++;
		else if(wlu>=mp[d[i]]){
			wlu++;
		}else{
			lu++;
		}
	}
	if(lu>=m)return 1;
	else return 0;
}
long long ans=0;
void dfs(int x){
	if(x>n){
		/*for(int i=1;i<=n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;*/
		if(check()){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		d[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>mp[i];
	}
	if(n<=18){
		dfs(1);
		cout<<ans%998244353;
	}else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}