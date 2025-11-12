#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll num[101]={0};
	for(int i=0;i<n*m;i++){
		scanf("%lld",&num[i]);
	}ll nm=num[0];
	sort(num,num+n*m);
	ll gg=n*m-1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(num[gg]==nm){
					cout<<i<<' '<<j;
					return 0;
				}gg--;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(num[gg]==nm){
					cout<<i<<' '<<j;
					return 0;
				}gg--;
			}
		}
	}
	return 0;
}

