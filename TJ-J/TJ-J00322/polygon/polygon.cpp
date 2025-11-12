#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int p=998244353;
ll n,a[6001],ans;
void dfs(int x,int k,ll sum,ll mx){
	if(k>=3){
		if(sum>2*mx){
			ans++; 
			ans%=p;
		}
	}
	if(x>n||k>n) return;
	for(int i=x;i<=n;i++){
		dfs(i+1,k+1,sum+a[i],a[i]);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans%p;
	return 0;
}

