#include<bits/stdc++.h>

using namespace std;

const int N=110;
int a[N*N],b[N][N],n,m,cnt,a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[++cnt];
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
