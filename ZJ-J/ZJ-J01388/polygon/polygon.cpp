#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;
int a[5010],n;
long long ans=0;
const int mod=998244353;
void dfs(int dep,int sum,int maxn){
	if(dep>n){
		if(sum>2*maxn){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(dep+1,sum,maxn);
	dfs(dep+1,sum+a[dep],max(maxn,a[dep]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
    return 0;
}
//AFO.
//O(2^n),only 40 pts.