#include<bits/stdc++.h>
using namespace std;
long long n,m,j=1,suma=0,sumb=0,a[5000];
long long jc(int n){
	if(n=0)  return 1;
	for(int i=2;i<=n;i++){
		j=j*i;
	}
	return j;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])  m=a[i];
	}
	if(n==3){
		for(int i=0;i<3;i++){
			suma+=a[i];
		}
		if(suma>2*m)  cout<<1;
		else  cout<<0;
	}
	else if(m==1){
		for(int i=3;i<=n;i++){
			sumb=sumb+jc(n)/(jc(i)*jc(n-i));
		}
		cout<<sumb;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
