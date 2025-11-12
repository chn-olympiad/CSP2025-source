#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<pll> velp;
typedef vector<vel> vevel;
const ll mo=998244353;
const ll N=5001;
ll dp[3][N+3];
void slv(){
	ll n;
	cin>>n;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v.begin()+1,v.begin()+1+n);
	ll anss=0;
	for(int i=1;i<=n;i++){
		for(int j=5001;j>=0;j--){
			if(j>v[i]){
				anss+=dp[2][j];
				anss%=mo;
			}
			dp[2][min(5001ll,j+v[i])]+=dp[2][j];
			dp[2][min(5001ll,j+v[i])]%=mo;
			
		}
		for(int j=5001;j>=0;j--){
			if(j>v[i]){
				anss+=dp[1][j];
				anss%=mo;
			}
			dp[2][min(5001ll,j+v[i])]+=dp[1][j];
			dp[2][min(5001ll,j+v[i])]%=mo;
			
		}
		for(int j=1;j<i;j++){
			dp[1][min(5001ll,v[j]+v[i])]++;
			dp[1][min(5001ll,v[j]+v[i])]%=mo;
		}
	}
	cout<<anss;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}