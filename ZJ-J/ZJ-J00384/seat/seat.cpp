#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0;
ll a[105],a1,b[20][20];
ll ps(ll a,ll b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,ps);
	for(int i=1; i<=m; i++){
		if(i%2==1){
			for(int j=1; j<=n; j++){
				b[i][j]=a[++ans];
				if(a[ans]==a1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}else{
			for(int j=n; j>0; j--){
				b[i][j]=a[++ans];
				if(a[ans]==a1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}

