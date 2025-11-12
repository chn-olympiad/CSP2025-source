#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n,m,c,r,d,sum=0;
	char a[1000];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int j=2;j<=n*m;j++){
		if(a[j]>d){
			sum++;
		}
	}
	sum+=1;
	if(sum%m!=0){
		c=sum/m+1;
	}else{
		c=sum/m;
	} 
	if(sum%m!=0){
		r=sum%m;
	}else{
		r=m;
	}
	if(sum<=m){
		c=1;r=sum+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
