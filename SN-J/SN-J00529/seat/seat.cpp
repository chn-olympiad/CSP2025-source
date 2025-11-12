#include<bits/stdc++.h>
using namespace std;
int a[101];
bool gg(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int b[n+1][m+1];
	bool u=0;
	int y=1;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+n*m+1,gg);
	for (int i=1;i<=m;i++){
		if (!u){
			for (int j=1;j<=n;j++){
				if (j+1<=n){
					b[j][i] = a[y];
					y++;
					if (b[j][i] == xr) {
						cout<<i<<" "<<j;
						return 0;
					}
				}else if (j+1>n){
					u=!u;
					b[j][i] = a[y];
					y++;
					if (b[j][i] == xr) {
						cout<<i<<" "<<j;
						return 0;
					}
				}
			}
		}else{
			for (int j=n;j>=1;j--){
				if ((j-1)>=1){
					b[j][i] = a[y];
					y++;
					if (b[j][i] == xr) {
						cout<<i<<" "<<j;
						return 0;
					}
				}else if(j-1<1){
					u=!u;
					b[j][i] = a[y];
					y++;
					if (b[j][i] == xr) {
						cout<<i<<" "<<j;
						return 0;
					}
				}
			}
		}
		
	}
	
	return 0;
}
