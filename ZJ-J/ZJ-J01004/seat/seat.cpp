#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,y,t,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	t=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==t)k=i+1;
	}
	if(k%n==0)y=k/n;
	else y=k/n+1;
	if(y%2==0){
		if(k%n==0)x=1;
		else x=n+1-k%n;
	}
	else{
		if(k%n==0)x=n;
		else x=k%n;
	} 
	cout<<y<<" "<<x;
	return 0;
}