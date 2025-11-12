#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//ÐÐ£¬ÁÐ 
	cin>>n>>m;
	int a[15][15];
	int t=100;
	int r;cin>>r;
	for(int i=1;i<=m;i++){
		if(i%2==0){
		for(int j=n;j>=1;j--){
				a[i][j]=t;
				if(r==a[i][j]){
					cout<<i<<" "<<j;
					return 0;
				}
				t--;	
				}
			}
			if(i%2==1){
				for(int j=1;j<=n;j++){
			a[i][j]=t;
			if(r==a[i][j]){
					cout<<i<<" "<<j;
					return 0;
				}
			t--;
			}
		}
	}
	return 0;
}
