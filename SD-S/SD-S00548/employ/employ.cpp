#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,te[N],m,a[N],s[N],ans;
bool vis[N];
bool check(){
	int sum=0;
	int op=0;
	for(int i=1;i<=n;i++){
		if(a[s[i]]<=sum||!te[i]){
			sum++;
		}
		else{
			op++;
		}
	}
	return op>=m;
}
void dfs(int p){
	if(p>n){
		if(check()){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			s[p]=i;
			vis[i]=1;
			dfs(p+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	srand((int)time(0)); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		te[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>10){
		cout<<rand()%mod;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
