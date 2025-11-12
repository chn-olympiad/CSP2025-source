#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct peo{
	ll x,id;
}a[1010];
ll n,m,p;
ll xx,yy;
bool cmp(peo x,peo y){
	return x.x>y.x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i].x,a[i].id=i;
	sort(a+1,a+(n*m)+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i].id==1){p=i;break;}
	}
	xx=ceil(1.0*p/n),yy=p%n;
	if(yy==0)yy=n;
	if(xx%2==0){
		yy=n-yy+1;
	}
	cout<<xx<<" "<<yy<<"\n";
	return 0;
}
