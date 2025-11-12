#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,pk,a[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	pk=a[1];
	sort(a+1,a+n*m+1);
	k=n*m;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				if(a[k]==pk) cout<<j<<' '<<i;
				k--;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[k]==pk) cout<<j<<' '<<i;
				k--;
			}
		}
	}
	return 0;
}
