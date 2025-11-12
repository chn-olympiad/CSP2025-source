#include<bits/stdc++.h>
using namespace std;
int n,flag,ans[50000000];
int a[1000000],k=4,m,nn;
int l=1;
int dfs(int k,int nn){
	m=k+1;
	while(m--&&m>2){
		l=m-2;
		ans[k]=ans[k]+(l+1)*l/2;
	}
	ans[k]+=ans[k-1];
	if(k==nn){
		return ans[k];
	}
	dfs(k+1,nn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		} 
	}
	int nn=n;
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	ans[3]=1;
	if(flag==0){
		dfs(4,nn);
		cout<<ans[nn]%998244353;
	}
	return 0;
}

