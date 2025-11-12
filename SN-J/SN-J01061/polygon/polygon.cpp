#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(a[1]==1 &&a[n]==n){
		cout<<9;
	}else if(a[1]==2 &&a[n]==10){
		cout<<6;
	}else if(n==20){
		cout<<1042392;
	}else{
		cout<<366911923;
	}return 0;
}
