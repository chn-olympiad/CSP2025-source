#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[5010],ans;
const ll M=998244353;
void dfs(ll x,ll y,ll m){
	if(x>n){
		if(y>2*m){
			ans++;
			ans%=M;
		}
		return ;
	}
	dfs(x+1,y,m);
	dfs(x+1,y+a[x],a[x]); 
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0);cout<<ans;
	return 0;
} 
