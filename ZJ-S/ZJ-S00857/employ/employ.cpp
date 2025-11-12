#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,c[N],a[N],ans,mod=998244353;
string s;
bool vis[N];
bool check(){
	int cnt=0,sv=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt++;
		}
		else{
			if(c[a[i]]<=cnt){
				cnt++;
			}
			else{
				sv++;
			}
		}
	}
	return sv>=m;
}
void dfs(int dep){
	if(dep>n){
		if(check()){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='!'+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}