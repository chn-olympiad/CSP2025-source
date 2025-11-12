#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,b,c;
struct fensi{
	ll f,t;
}a[105];
bool cmp(fensi x,fensi y){
	return x.f>y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].f,a[i].t=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].t==1){
			c=i;break;
		}
	}
	ll d=int(c/n);
	ll e=c%n;
	if(e!=0){
		if(d%2)cout<<d+1<<" "<<n-e+1;
		else cout<<d+1<<" "<<e;
	}else{
		if(d%2)cout<<d<<" "<<n;
		else cout<<d<<" "<<1;
	}
	return 0;
}
