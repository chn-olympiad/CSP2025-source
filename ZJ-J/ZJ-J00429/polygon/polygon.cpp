#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int mod=998244353;
long long cc(int c){
	long long num=0;
	for(int i=1;i<=c;i++){
		num+=i;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	maxx*=2;
	if(n==3){
		if(sum>maxx){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		long long ans=0;
		for(int i=1;i<=n-2;i++){
			ans=(ans+cc(i))%mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}