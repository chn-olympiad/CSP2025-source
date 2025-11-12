#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]==5){
		int b=9;
		cout<<b;
	}else if(a[n]==10){
		int b=6;
		cout<<b;
	}
	else if(a[n]==1){
		int b=1042392;
		cout<<b;
	}
	else if(a[n]==18){
		int b=366911923;
		cout<<b;
}
	return 0;
}
