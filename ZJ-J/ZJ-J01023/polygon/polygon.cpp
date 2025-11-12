//正解疑似dp
//9:20 40分暴力 + 24分a[i]==1(1<=i<=n)特殊性质 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,a[5005];
ll sum;
void dfs(int k,int max_n,ll ans,int p){
	if(k==n+1){
		if(p>=3&&ans>max_n*2){
			sum++;
			sum %= mod;
		}
		return;
	}
	dfs(k+1,max(max_n,a[k]),ans+a[k],p+1);
	dfs(k+1,max_n,ans,p);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool p = true;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p = false;
		}
	}
	if(p==true){
		//2^n-C(n,0)-C(n,1)-C(n,2)
		sum = 1;
		for(int i = 1;i<=n;i++){
			sum *= 2;
			sum %= mod;
		}
		sum = sum-1-n-n*(n-1)/2;
		sum = (sum+mod)%mod;
		cout<<sum;
	}
	else{
		dfs(1,-1,0,0);
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
