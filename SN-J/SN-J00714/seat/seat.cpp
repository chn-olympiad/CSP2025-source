#include<bits/stdc++.h>
using namespace std;
int a[10000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int n=1;
	cin>>a[n];
	int t=a[n];
	int p=1;
	
	for(n=2;n<=x*y;n++){
		cin>>a[n];
		
		if(a[n]>t){
			p++;
		}	
		
	}
	int ax=1,ay=1;
	int ans=1;
	int l=1;
	for(int i=1;i<n;i++){
		
		if(ans==p){
			break;
		}
		ax+=l;
		ans++;
		if(ax>x||ax<1){
			l=-l;
			ax+=l;
			ay++;
		}
		
	}
	cout<<ay<<' '<<ax;
	return 0;
	
}
