#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
const int N=5007;
int a[N];
long long ans;
void dfs(int k,int sum,int lmax){
	if(k>n){
		if(sum-lmax>lmax){
			++ans;
			ans%=M;
		}
		return;
	}
	dfs(k+1,sum+a[k],max(lmax,a[k]));//xuan
	dfs(k+1,sum,lmax);//bu xuan
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
