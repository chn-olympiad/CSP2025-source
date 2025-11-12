#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll n,m,nmmn,a[110][110],grdcj[10010],xiaor,ct=1;
bool cmpp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>grdcj[i];
	}
	xiaor=grdcj[1];
	sort(grdcj+1,grdcj+n*m+1,cmpp);
	//for(ll i=1;i<=n*m;i++) cout<<grdcj[i]<<" ";
	//cout<<"\n";
	for(ll i=1;i<=m;i++){
		if(i%2==1){
			for(ll j=1;j<=n;j++){
				a[j][i]=grdcj[ct++];
			}
		}else if(i%2==0){
			for(ll j=n;j>=1;j--){
				a[j][i]=grdcj[ct++];
			}
		}
		
	}
	/*
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i][j]==xiaor){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
