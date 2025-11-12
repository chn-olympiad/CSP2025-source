#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		b[x][y]=a[i];
		if(x==n&&y%2||x==1&&y%2==0)y++;
		else{
			if(y%2)x++;
			else x--;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==r){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
	return 0;
}