#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=15;
ll n,m,a[N*N],cnt=1;
ll t;
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool flag=1;//+/-
	for(ll i=1;i<=m;i++){
		if(flag){
			for(ll j=1;j<=n;j++){
				if(a[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}else{
			for(ll j=n;j>=1;j--){
				if(a[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		flag=!flag;
	}
	return 0;
}
