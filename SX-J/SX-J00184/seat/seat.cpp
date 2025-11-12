#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool com(int x,int y){
	if(x>y) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cj=a[1];
	int zw=0;
	sort(a+1,a+n*m+1,com);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			zw=i;break;
		}
	}
	int c;
	if(zw<n) c=1;
	else{
		if(zw%n==0) c=zw/n;
		else c=zw/n+1;
	}
	cout<<c<<" ";
	if(c%2==1) {
		if(zw%n!=0) cout<<zw%n;
		else cout<<n;
	}
	else {
		if(zw%n!=0) cout<<n-zw%n+1;
		else cout<<1;
	}

	return 0;
}