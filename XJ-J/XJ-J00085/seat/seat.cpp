#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[110],zs,sy,cj,ans,cs,ys,h,l,rs;
int main() {
	freopen("seat.in","r"stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	zs=n*m;
	cj=a[1];
	sort(a+1,a+1+zs,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			ans=i;
		}
	}
	cs=ans/n;
	ys=ans%n;
	if(ys>0){
		cs++;
	}
	cout<<cs<<" ";
	if(cs==1){
		cout<<ans;
	}
	else{
		rs=(cs-1)*n;
		if(cs%2==1){
			cout<<ans-rs;
		}
		else{
			sy=ans-rs;
			cout<<n-sy+1;
		}
	}
	return 0;
}
