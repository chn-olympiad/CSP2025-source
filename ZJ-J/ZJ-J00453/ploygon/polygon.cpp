#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		
	}
	return 0;
}
