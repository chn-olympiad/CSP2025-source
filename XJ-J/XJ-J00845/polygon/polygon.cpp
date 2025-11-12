#include<bits/stdc++.h>//´¿Æ­·Ö 
using namespace std;
int n,a[5005],c=-1; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=max(c,a[i]);
	}
	if((a[1]+a[2]+a[3])>2*c){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
