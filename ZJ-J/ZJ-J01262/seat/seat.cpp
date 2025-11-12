#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N],b[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int u=a[1];
	sort(a+1,a+n*m+1,[](int x,int y){
		return x>y;
	});
	int tot=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++tot];
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++tot];
			}
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(b[j][i]==u){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}