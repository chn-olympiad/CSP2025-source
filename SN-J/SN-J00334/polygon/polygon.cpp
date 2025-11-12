#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
int n;
int a[5005];
int C(int x,int y){
	if(x==y or x==0)return 1;
	return (C(x-1,y-1)%M+C(x,y-1)%M)%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(a[3],max(a[1],a[2]))){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		ll ans=0;
		for(int i=3;i<=n;i++){
			ans+=C(i,n)%M;
		}
		cout<<ans%M;
	}
	return 0;
}
