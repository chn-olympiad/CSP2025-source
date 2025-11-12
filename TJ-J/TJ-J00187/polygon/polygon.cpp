#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[3]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if((a[1]+a[2]<=a[0]||a[0]+a[1]<=a[2]||a[0]+a[2]<=a[1])&&n<3){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
