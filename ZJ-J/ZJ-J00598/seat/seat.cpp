#include<bits/stdc++.h>
using namespace std;
int r,n,m,a[10005];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	bool flag=0;int cnt=1;
	for(int i=1;i<=m;i++){
		if(!flag)
			for(int j=1;j<=n;j++){
				b[j][i]=a[cnt++];
			}
		else
			for(int j=1;j<=n;j++){
				b[n-j+1][i]=a[cnt++];
			}
		flag=!flag;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==r){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
	return 0;
}
//8:51 200pts
