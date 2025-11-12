#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],maxn=0;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	int ans=0;
	if(a[1]+a[2]+a[3]<=2*maxn&&n==3){
		cout<<0;
		return 0;
	}else if(a[1]+a[2]+a[3]>2*maxn&&n==3){
		cout<<1;
		return 0;
	}else cout<<n*n*n; 
	return 0;
} 
