#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,gal;
bool use[5005];
void dfs(int k,int sum,int maxi,int m,int la){
	gal++;
	if(gal>1e8) return;
	if(k==m){
		if(sum>2*maxi) {ans++;
			ans=ans%998244353;
		}
		
		return ;}
	for(int i=la;i<=n;i++)
	if(use[i]==false){
		use[i]=true;
		dfs(k+1,sum+a[i],max(a[i],maxi),m,i);
		use[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int m=n;m>=3;m--)
	dfs(0,0,0,m,0);
	ans=(ans+1)/2;
	cout<<ans;
	return 0;
}
