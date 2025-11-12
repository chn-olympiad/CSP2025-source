#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],b,x,y,id,z;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			id=i%(2*n);
			if(id==0)id=2*n;
			z=i/2/n+1;
			if(id<=n){
				y=id%n;
				if(y==0)y=n;
			}
			else{
				y=n-id%n+1;
			}
			if(id<=n){
				x=z*2-1;
			}
			if(id>n){
				x=z*2;
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
}
