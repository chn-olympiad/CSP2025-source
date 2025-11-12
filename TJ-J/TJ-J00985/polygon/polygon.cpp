#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[9999],x=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		if(a[i]>x){
			x=a[i];
		}
	}
	if(x*2<num){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
