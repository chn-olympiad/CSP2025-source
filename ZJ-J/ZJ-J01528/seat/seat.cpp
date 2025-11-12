#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],b[11][11];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=n*m,x=a[1];
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				b[i][j]=a[t];
				t--;	
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[t];
				t--;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}