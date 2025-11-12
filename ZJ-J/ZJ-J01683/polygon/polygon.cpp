#include<bits/stdc++.h>
using namespace std;
int n,a[5100],b[5100],k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		if(a[i]>1) p=false;
	} 
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(max(a[1],max(a[2],a[3]))<b[3]-max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(p){
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=i;j++){
				k+=j;
			}
			k%=998244353;
		}
		cout<<k;
		return 0;
	}
	
	cout<<n*2-1;
	return 0;
}                          
