#include<bits/stdc++.h>
using namespace std;
struct node{
	int fs,bh;
}a[105];
int n,m,wz,xs;
bool cmp(node x,node y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		a[i].bh=i;
		if(i==1){
			xs=a[i].fs;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].fs==xs){
			wz=i;
		}
	}
	if(((wz+n-1)/n)%2!=0){
		int h=(wz+n-1)/n,l;
		if(wz%n==0){
			l=n;
		}
		else{
			l=wz%n;
		}
		cout<<h<<" "<<l;
	}
	else{
		int h=(wz+n-1)/n,l;
		if(wz%n==0){
			cout<<h<<" "<<1;
			return 0;
		}
		int l1=wz-wz/n*n;
		l=n-(l1-1);
		cout<<h<<" "<<l;
	}	
	return 0;
}
