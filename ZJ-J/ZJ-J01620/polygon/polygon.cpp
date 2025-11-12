#include<bits/stdc++.h>
using namespace std;
long long a[5001],n,ans,maxn,f[5001],ff;
void dfs(long long s,long long id){
	if((f[id]+s)<=maxn)return;
	if(s>maxn)ans=(ans+1)%998244353;
	for(int i=id;i>=1;i--)dfs(s+a[i],i-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    f[i]=a[i]+f[i-1];
	    if(a[i]!=1)ff=1;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		maxn=a[i];
		dfs(0,i-1);
	}
	cout<<ans;
}
