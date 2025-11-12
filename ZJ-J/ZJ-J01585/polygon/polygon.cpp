#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N];
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m=n;
	n-=2;
	int cnt=2;
	long long ans=0;
	if(n==3){
		cout<<1;
		return 0;
	}
	while(n>=1){
		ans=ans+((1+n)*n%MOD)/2*m%MOD;
		n--;
	//	cout<<ans<<endl;
	}
	cout<<ans+1;
	return 0;
}
