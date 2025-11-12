#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[0]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
