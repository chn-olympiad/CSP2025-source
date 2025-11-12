#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[1];
	int cr;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaor){
			cr=i;
			break;
		}
	}
	int c=(cr-1)/n+1;
	int r;
	if(c%2==1){
		r=cr%n;
		if(r==0){
			r=n;
		}
	}
	else{
		r=n-(cr-1)%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
