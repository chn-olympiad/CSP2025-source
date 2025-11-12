#include<bits/stdc++.h>
using namespace std;
int n,b=1;
int a[5005];
int hhh(int x){
	if(x==0) return b;
	else b*=x;hhh(x-1);
}
int main(){
	freopen("polygon.in","r");
	freopen("polygon.out","w");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<hhh(n-3);	
	fclose("polygon.in");
	fclose("polygon.out");
	return 0;
}
