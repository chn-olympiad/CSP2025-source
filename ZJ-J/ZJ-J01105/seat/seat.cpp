#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1001];
bool cmp(ll q,ll p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll num=a[1];
	sort(a+1,a+n*m+1,cmp);
	ll sum=0;
	for(ll j=1;j<=m;j++){
		if(j%2==1){
			for(ll i=1;i<=n;i++){
				sum++;
				if(a[sum]==num){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(ll i=n;i>=1;i--){
				sum++;
				if(a[sum]==num){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}

