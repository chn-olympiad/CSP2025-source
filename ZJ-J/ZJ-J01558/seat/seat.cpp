#include<bits/stdc++.h>
using namespace std;
int m,n,a[105][105],c,cnt=1,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(i==1&&j==1) c=a[i][j];
			else if(a[i][j]>c) cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		if(m%2){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}	
		}	
		else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}