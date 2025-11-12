#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
const int M=998244353;
ll n,ans;
ll num[N];
void dfs(ll a,ll b,ll h,ll m){
	if(b==0){
		if(h>m*2){
			ans++;
			ans=ans%M;
		}
		return;
	}
	for(int i=a+1;i<=n;i++){
		dfs(i,b-1,h+num[i],max(m,num[i]));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,-1);
	}
	cout<<ans;
	return 0;
}
