#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e3+5,mod=998244353;
int n;
int a[N],sum[N]={0},ans[N]={0};

int DFS(int i,int sum,int maxv,int choosed){
	if(i==n+1){
		if(sum>2*maxv&&choosed>=3){
			return 1;
		}else{
			return 0;
		}
	}
	return DFS(i+1,sum+a[i],max(maxv,a[i]),choosed+1)+DFS(i+1,sum,maxv,choosed); 
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxai=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(maxai,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=20){
		cout<<DFS(1,0,-1,0)%mod;
		return 0;
	}
	if(maxai==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans=((ans+mod)-n-(n*(n-1)/2)-1)%mod;
		cout<<ans;
		return 0;
	}
	cout<<DFS(1,0,-1,0)%mod;
	return 0;
} 
