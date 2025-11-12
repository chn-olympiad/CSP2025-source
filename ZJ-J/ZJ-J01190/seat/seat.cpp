#include<bits/stdc++.h>
using namespace std;
int s[15][15],n,m,sum[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sum[i];
	}
	int ans=sum[1];
	sort(sum+1,sum+1+n*m);
	int o=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(sum[o]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				s[i][j]=sum[o];
				o--;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(sum[o]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				s[i][j]=sum[o];
				o--;
			}
		}
	}
	return 0;
}
