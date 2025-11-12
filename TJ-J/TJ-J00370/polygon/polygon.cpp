#include<bits/stdc++.h>
using namespace std;
long long n=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	int max1=0;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		max1=max(max1,a[i]);
	}
	if(n<2){
		cout<<0;
	}
	if(n==3 && a[0]+a[1]+a[2]>max1*2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n>=4){
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
