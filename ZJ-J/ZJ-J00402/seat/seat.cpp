#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,a,sum=1;
	cin>>n>>m;
	cin>>a;
	for(ll i=2;i<=n*m;i++){
		ll b;
		cin>>b;
		if(b>a){
			sum++;
		}
	}
	ll d=sum/n,s=sum%n;
	if(s!=0) d++;
	else s=n;
	cout<<d<<' ';
	if(d%2==1) cout<<s;
	else cout<<n-s+1;
	return 0;
}
