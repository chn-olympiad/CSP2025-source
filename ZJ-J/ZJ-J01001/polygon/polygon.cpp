#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans;
int he(int x,int y){
	sum=0;
	for(int i=x;i<=y;i++){
		sum+=a[i];
	}
	return 0;
}
int maxx(int x,int y){
	ans=0;
	for(int i=x;i<=y;i++){
		ans=max(ans,a[i]);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	he(1,3);
	maxx(1,3);
	if(n==3){
		if(sum>2*ans){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	return 0;
}
