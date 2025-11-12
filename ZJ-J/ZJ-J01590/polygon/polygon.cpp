#include <iostream>
#include <algorithm>
using namespace std;
const int MOD=998244353;
long long n,a[5010],anw;
long long r(int x){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=MOD;
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
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=3;i<=n;i++){
			anw+=r(n)/r(n-i)/r(i);
			anw%=MOD;
		}
		cout<<anw;
	}
	return 0;
}
