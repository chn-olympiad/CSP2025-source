#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans,a[200],x;
int b[100][100];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[n*m-x];
				x++;
				if(b[i][j]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[n*m-x];
				x++;
				if(b[i][j]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}