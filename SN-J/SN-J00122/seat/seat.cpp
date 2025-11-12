#include <bits/stdc++.h>
using namespace std;
int n,m,a[130],b[105],c,s=0;
int main(){
	std::ifstream cin("seat.in");
	std::ofstream cout("seat.out");
	cin>>n>>m;
	for(int i=0;i<n*m;i++) {
		cin>>a[i];
		b[a[i]]++;
	}
	c=a[0];
	for(int i=100;i>=0;i--)
		if(i>=c) s+=b[i];
	for(int i=1;i<=n;i++){
	if(i%2==1) 
	 for(int j=1;j<=m;j++)
		if((i-1)*n+j==s) {
			cout<<i<<" "<<j;
			break;
		}
	if(i%2==0) 
	 for(int j=m;j>=1;j--)
	  	if((i-1)*n+(n-j+1)==s){
			cout<<i<<" "<<j;
			break;
		} 
	}
	return 0;
}
