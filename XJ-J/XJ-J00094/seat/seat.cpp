#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,sR;
int a[N],st[15][15];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sR=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int i_a=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				st[i][j]=a[++i_a];
			}
		}else{
			for(int j=n;j>=1;j--){
				st[i][j]=a[++i_a];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(st[i][j]==sR){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
