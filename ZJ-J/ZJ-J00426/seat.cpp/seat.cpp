#include<bits/stdc++.h>
using namespace std;
int a[100200];
int x=0;
int y=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i;
		}
	}
	x=p/n+(p%n>=1);
	if(x%2==0){
		y=n-(p%n)+1;
		if(p%n==0){
			y=1;
		}
	}
	else{
		y=p%n;
		if(p%n==0){
			y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
