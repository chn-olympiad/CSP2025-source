#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			ans++;
		}
	}
	for(j=1;j<=m;j++){
		if(j%2==1){
			for(i=1;i<=n;i++){
				if(ans==0){
					cout<<j<<" "<<i;
					return 0;
				}
				ans--;
			}
		}
		else{
			for(i=n;i>=1;i--){
				if(ans==0){
					cout<<j<<" "<<i;
					return 0;
				}
				ans--;
			}
		}
	}
}
