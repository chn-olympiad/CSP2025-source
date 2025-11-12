#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct tt{
	int x,y;
}a[N];
int n,m,t;
int cmp(tt x,tt y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].y==1){
			t=i;
			break;
		}
	}
	int x=ceil(t/1.0/n);
	cout<<x<<" ";
	if(x%2==1){
		if(t%n==0){
			cout<<n;
		}
		else{
			cout<<t%n;
		}
	}
	else{
		if(t%n==0){
			cout<<1;
		}
		else{
			cout<<n-t%n+1;
		}
	}
	return 0;
}