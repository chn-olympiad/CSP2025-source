#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,x,y,s,sum;
	cin>>n>>m>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			sum=i;
			break;
		}
	}
	y=sum%(2*n);
	if(y>n){
		y=y-n;
		y=n-y+1;
	}
	x=sum/n+1;
	cout<<x<<" "<<y;
	return 0;
}
