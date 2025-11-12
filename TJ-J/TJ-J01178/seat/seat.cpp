#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m;
struct qeurq{
	ll id;
	ll val;
}a[105],x[15][15];
bool cmp(qeurq x,qeurq y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	ll ii=1;
	for(ll j=1;j<=m;j++){
		if(j%2==0){
			for(ll i=n;i>=1;i--){
				x[i][j].id=a[ii].id;
				x[i][j].val=a[ii].val;
				ii++;
			}
		}
		else{
			for(ll i=1;i<=n;i++){
				x[i][j].id=a[ii].id;
				x[i][j].val=a[ii].val;
				ii++;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(x[i][j].id==1){
				cout<<j<<" "<<i;
				return 0;
			}
//			cout<<x[i][j].val<<"	";
		}
//		cout<<"\n";
	}
	return 0;
}
