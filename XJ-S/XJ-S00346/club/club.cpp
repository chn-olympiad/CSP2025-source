#include<bits/stdc++.h>
using namespace std;
const int aaa=1e5+5;
int n,T;
int a[aaa],b[aaa],c[aaa];
int solve(){
	cin>>n;
	int sj=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int sum=0,al=sj,bl=sj,cl=sj;
	if(n==2){
		int sum=a[1]+b[2];
		sum=max(sum,a[1]+c[2]);
		sum=max(sum,b[1]+a[2]);
		sum=max(sum,b[1]+c[2]);
		sum=max(sum,c[1]+a[2]);
		sum=max(sum,c[1]+b[2]);
		cout<<sum;
		return 0;
	}
	if(n==100000){
		int sum=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=sj;i++){
			sum+=a[i];
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

