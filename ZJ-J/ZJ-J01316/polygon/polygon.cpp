#include<bits/stdc++.h>
using namespace std;
long long n,x,a,b,c,ba[10000],ans;
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a<b+c&&b<a+c&&c<a+b){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>ba[i];
	}
	for(int i=1;i<=n;i++){
		int x=1;
		for(int j=1;j<=i;j++){
			x=(x*(n-i+1)/j)%mod;
		}
		ans=(ans+x)%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
