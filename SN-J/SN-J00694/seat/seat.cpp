#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100],k,c,r,cntn;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		k=a[1];
	}
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(k==a[i]){
			cntn=i;
		}
	}
	for(int h=n*m;h>=1;h--){
		for(int j=1;j<=m;j++){
			if(j%2!=0){
				for(int i=1;i<=n;i++){
					if(a[h]==a[cntn]){
						r=i,c=j;
						break;
					}
				}
			}else{
				for(int i=n;i>=1;i--){
					if(a[h]==a[cntn]){
						r=i,c=j;
						break;
					}
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
