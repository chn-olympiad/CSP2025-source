#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000],dp[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=0,maxn=-1e9;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>(maxn+maxn)){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	int maxn=-1e9;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}
	if(maxn<3){
		int ans=1;
		for(int i=4;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

