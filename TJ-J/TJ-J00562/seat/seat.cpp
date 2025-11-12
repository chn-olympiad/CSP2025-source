#include<bits/stdc++.h>
using namespace std;
int a[101];
int ans[11][11];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[0];
	int ans;
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<n*m;i++){
		if(s=a[i]) ans=i;
	}
	int ax,ay;
	if(ans%m==0) ay=ans/m;
	else ay=ans/m+1;
	cout<<ay;
	return 0;
}
