#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10+5,MAX=100+5;
struct node{
	int id,b;
}a[MAX];
int zw[N][N];
bool cmp(node x,node y){
	return x.b>y.b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].b;
		a[i].id=i;
	}
	for(int j=1;j<=m;j++){
		int t=0;
		if(j%2==1){
			for(int i=1;i<=n;i++){
				t++;
				zw[i][j]=(j-1)*n+t;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				t++;
				zw[i][j]=(j-1)*n+t;
			}
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	//		cout<<i<<" "<<j<<" "<<zw[i][j]<<"--\n";
			if(zw[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97
*/
