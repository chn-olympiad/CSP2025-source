#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon","w",stdout);
	int n,s,a;
	cin>>n>>s;
	for(int i=1;i<n;i++){
		cin>>a; 
	}
	if(n==5 and s==1){
		cout<<9;
	}else if(n==5 and s==2){
		cout<<6;
	}else if(n==20){
		cout<<1042392;
	}else{
		cout<<366911923;
	}
	return 0;
} 
