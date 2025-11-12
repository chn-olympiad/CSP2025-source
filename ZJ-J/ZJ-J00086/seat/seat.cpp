#include<bits/stdc++.h>
using namespace std;
int b[15][15];
int a[105];
int c[105];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=0;
	for (int j=100;j>=0;j--){
		for (int i=1;i<=n*m;i++){
			if (a[i]==j){
				int b=a[i];
				ans++;
				c[i]=ans;
			}
		}
		if (ans==n*m){
			break;
		}
	}
	ans=c[1];
	int y;
	while (ans){
		if(ans<=n){
			cout<<1<<" "<<ans;
			return 0;
		}
		else {
			if (ans%n==0){
				y=ans/n;
			}
			else y=ans/n+1;
		}
		if (y%2==1){
			cout<<y<<" "<<ans-y*n+n;
			return 0;
		}
		else {
			cout<<y<<" "<<y*n-ans+1;
			return 0;
		}
	}
	return 0;
}
