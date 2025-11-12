#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int const N=5005;
long long n,slt,maxn,a[N];
void dfs(long long id,long long sum,long long mx){
	if(id>n){
		if(sum>mx*2){
			slt++;
			slt%=mod;
		}
		return;
	}
	dfs(id+1,sum+a[id],max(maxn,a[id]));
	dfs(id+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<slt;
	return 0;
}
