#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a[105],b[15][15],T;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[++T];
	int R=a[1];
	T=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)for(int j=1;j<=n;j++)b[j][i]=a[++T];
		else for(int j=n;j>0;j--)b[j][i]=a[++T];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==R){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
