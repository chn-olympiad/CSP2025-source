#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
struct stu{
	ll num,id;
}a[N];
bool cmp(stu x,stu y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].num;	
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	ll key;
	for(ll i=1;i<=n*m;i++){
		if(a[i].id==1){
			key=i;
			break;
		}
	}
	ll y;
	if(key%n==0)y=key/n;
	else y=key/n+1;
	cout<<y<<" ";
	ll ans=0;
	for(int i=(y-1)*n+1;i<=y*n;i++){
		ans++;
		if(a[i].id==1)break;
	}
	if(y%2==1)cout<<ans;
	else cout<<n-ans+1;
	return 0;
}
