#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,id;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			id=i;
			break;
		}
	}
	cout<<id<<"\n";
	if(id%n==0){
		r=id/n;
	}
	else r=id/n+1;
	int t=id%n;
	if(r%2){
		if(t==0){
			c=m;
		}
		else c=id%n;
	}
	else{
		if(t==0){
			c=1;
		}
		else c=n-id%n+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
