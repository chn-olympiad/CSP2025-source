#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[125],b[125];
int c,r;
int wzh;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			wzh=i;
		}
	}
	c=(wzh+n-1)/n;
	if(c%2==0){
		if(wzh%n==0){
			r=1;
		}else{
			r=n-(wzh%n)+1;
		}	
	}else{
		if(wzh%n==0){
			r=n;
		}else{
			r=wzh%n;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}