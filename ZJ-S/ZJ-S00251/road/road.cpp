#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20000][8];
ll b[2000000][10];

ll c[20000];
int main(){
	freopen("raod.in","w",stdin);
	freopen("raod.out","a",stdout);
	
	ll n,m,k;
	cin>>n>>m>>k;
	ll sum=0;
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
	}
	
	if(k==0){
		for(ll i=1;i<=m;i++){
			c[i]=a[i][3];
		}
		sort(c+1,c+m+1);
		for(ll i=1;i<=n-1;i++){
			sum+=c[i];
		}
		cout<<sum;
		return 0;
	}
	else {
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=5;j++){
				cin>>b[i][j];
			}
		}
		for(ll i=1;i<=m;i++){
			c[i]=a[i][3];
		}
		sort(c+1,c+m+1);
		for(ll i=1;i<=n-1-k;i++){
			sum+=c[i];
		}
		cout<<sum;
	}
	return 0;
} 
