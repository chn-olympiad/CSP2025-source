#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+10;
ll n,m;
ll a[N],R,w;
bool cmp(ll q,ll h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;a[1]=R;
	for(ll i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==R){
			w=i;
			break;
		}
	}
	ll lie=(w+n-1)/n;
	ll hang=(w-1)%n+1;
	if(lie%2==0)hang=n+hang-1;
	cout<<lie<<" "<<hang;
	return 0;
}
