#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[125];
int b[55][55];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,r;
	cin>>n>>m;
	ll p=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+p+1);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[p];
				p--;
				if(b[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[p];
				p--;
				if(b[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}