#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans[15][15],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				ans[j][i]=a[cnt++];
			}
		}else{
			for(int j=n;j>=1;j--){
				ans[j][i]=a[cnt++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==k){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}