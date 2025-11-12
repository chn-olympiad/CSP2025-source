#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ll a[100005],n,m,tmp;
	cin>>n>>m;
	for(ll i=0;i<n*m;i++)cin>>a[i];
	tmp=a[0];
	sort(a,a+(n*m),cmp);
	ll k=0;
	for(ll i=1;i<=n;i++){
		if(i%2){
			for(ll j=1;j<=m;j++){
				if(a[k] == tmp){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				k++;
			}
		}else{
			for(ll j=m;j>=1;j--){
				if(a[k] == tmp){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}