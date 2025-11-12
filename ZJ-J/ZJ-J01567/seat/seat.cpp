#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001],n,m,c,j,seat[201][201],mubiao;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mubiao=a[1];
	sort(a+1,a+m*n+1);
	int num=m*n;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				seat[i][j]=a[num];
				num--;
			}
		}
		else {
			for(int j=n;j>=1;j--){
				seat[i][j]=a[num];
				num--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(seat[i][j]==mubiao){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}
