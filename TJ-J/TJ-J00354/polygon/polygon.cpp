#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353;
long long jq(long long a){
	long long ans=1;
	for(int i=1;i<=a;i++){
		ans=ans*i;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=jq(n)/jq(n-i)/jq(i);
	}
	cout<<ans;
	return 0;
} 
