#include<bits/stdc++.h>
using namespace std;
int n,ans,t,a[5005];
long long x;
bool f[5005],fl;
void dfs(int k,int id,int mx,int sum){
	if(k>t){
		if(sum>2*mx){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=id+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(k+1,i,max(mx,a[i]),sum+a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=1;
	}
	if(!fl){
		x=((n-2)*(n-1)/2)%998244353;
		cout<<x;
	}
	else {
		for(int len=3;len<=n;len++){
			t=len;
			dfs(1,0,0,0);
		}
		cout<<ans;
	}
}
