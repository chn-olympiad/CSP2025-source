#include<bits/stdc++.h>
using namespace std;
int n,m,x,k,ax,ay,a[205];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			k=i;
			break;
		}
	for(int i=1;i<=m;i++)
		if(i*n>=k){
			ax=i;
			ay=k-(i-1)*n;
			break;
		}
	if(ax%2==1){
		if(ay==0)
			ay=n;
	}
	else{
		ay=n-ay+1;
	}
	cout<<ax<<" "<<ay<<endl;
	return 0;
}
