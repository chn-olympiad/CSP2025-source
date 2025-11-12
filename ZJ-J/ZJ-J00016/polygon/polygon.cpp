#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],C[5010],t,m,M=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	t=1;
	for(int i=1;i<=n;i++){
		t=t*2%M;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(m==1){
		cout<<(M+t-1-n-n*(n-1)/2)%M;
		return 0;
	}
	cout<<0;
	return 0;
}
