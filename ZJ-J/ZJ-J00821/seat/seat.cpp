#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mys,myid;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			myid=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==myid){
			mys=i;
		}
	}
	int h=mys%n;
	if(h==0) h=n;
	int l=((mys+n-1)/n);
	if(l%2==0){
		h=(n+1)-h;
	}
	cout<<l<<" "<<h;
	return 0;
}
