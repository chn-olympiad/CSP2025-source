#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,a[10001],i,sum,f[101][101],j,ans;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	t=n*m;
	for(i=1;i<=t;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+t,cmp);
	sum=1;j=1;
	for(i=1;i<=m;i++){
		if(j<=n){
			for(j=1;j<=n;j++){
				f[j][i]=a[sum];
				sum++;
			}
		}
		else{
			for(j=n;j>=1;j--){
				f[j][i]=a[sum];
				sum++;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){	
			if(f[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
/*
#Shang4Shan3Ruo6Shui4
*/