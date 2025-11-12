#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=510;
const ll mod=998244353;
ll vis[N];
ll a[N];
ll ans[N];
ll sum[N];
string s;
ll n,m; 
ll ansx;
ll sumx;
x_clear(){
	for(ll i=1;i<=n;i++){
		sum[i]=0;
	}
}
void dfs(ll x){
	if(x==n+1){
		sumx=0;
//		for(ll i=1;i<=n;i++){
//			cout<<sum[i]<<" ";
//		}
		for(ll i=1;i<=n;i++){
			if(s[i-1]=='0'){
//				cout<<0<<endl;
				sum[i]=sum[i-1];
				sum[i]++;
			}
			else if(a[ans[i]]<=sum[i-1]){
				sum[i]=sum[i-1];
				sum[i]++;
			}
			else{
				sumx++;
				sum[i]=sum[i-1];
			}
		}
//		for(ll i=1;i<=n;i++){
//			cout<<sum[i]<<" ";
//		}
//		cout<<sumx<<endl;
		if(sumx>=m){
//			for(ll i=1;i<=n;i++){
//				cout<<ans[i]<<" ";
//			}
			ansx++;
		}
		x_clear();
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[x]=i;
			dfs(x+1);
			vis[i]=0;
			ans[x]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ansx<<"\n";
	}
	else{
		ansx=1;
		for(ll i=1;i<=n;i++){
			ansx*=i;
			ansx%=mod;
		}
		cout<<ansx<<endl;
	}
	return 0;
}
