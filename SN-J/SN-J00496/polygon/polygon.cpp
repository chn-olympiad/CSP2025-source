#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],sum,h[5005];
void dfs(int c,int h,int z,int g){
	if(c==n+1){
		if(h>2*z and g>=3){
			sum=(sum+1)%mod;
		}
		return ;
	}
	dfs(c+1,h+a[c],a[c],g+1);
	dfs(c+1,h,z,g);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<sum;
	return 0;
}
