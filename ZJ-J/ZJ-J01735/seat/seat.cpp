#include<bits/stdc++.h>
#define ll long long
const int N=1e6+10;
using namespace std;
ll n,m;
ll a[N],ind=0;
ll b[110][110];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			ind++;
			cin>>a[ind];
		}
	}
	ll ans=a[1];
	sort(a+1,a+ind+1);
	
	for(ll i=1;i<=m;i++){
		if(i%2==1){
			for(ll j=1;j<=n;j++){
				//b[j][i]=a[ind];
				if(a[ind]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				ind--;
			}
		}else{
			for(ll j=n;j>=1;j--){
				//b[j][i]=a[ind];
				if(a[ind]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				ind--;
			}
		}
	}
	cout<<-1<<" "<<-1<<endl;
	
	
	return 0;
}
