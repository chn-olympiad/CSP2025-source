#include<bits/stdc++.h>
#define int long long
using namespace std;
int c(x,y){
	int s=1,i=x;
	for(;i>x-y;i--){
		s*=i;
	}
	for(i=y;i>1;i--){
		s/=i;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(i=3;i<=n;i++){
		ans+=c(x,i);
		ans%=998244353;
	}
	cout<<ans;
}