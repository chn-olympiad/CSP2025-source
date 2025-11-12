#include<bits/stdc++.h>
using namespace std;
long long int n,ans;
const long long int M=998244353;
long long int c(long long int x){
	long long int a=1;
	x=min(x,n-x);
	for(long long int i=n;i>=n-x+1;i--){
		a*=i;
	}
	for(long long int i=x;i>=2;i--){
		a/=i;
	}a=a%M;
	return a;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=3;i<=n;i++){
		ans+=c(i);
		ans=ans%M;
	}cout<<ans;
	return 0;
}
