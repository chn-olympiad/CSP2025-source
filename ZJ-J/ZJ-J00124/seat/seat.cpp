#include <bits/stdc++.h>
using namespace std;
const int N=20;
int a[N*N],f[N][N],n,m,l,i,j,w,r;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;l=n*m;
	for(i=1;i<=l;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+l+1,cmp);
	for(i=1;i<=m;i++)
		if(i%2==1)
			for(j=1;j<=n;j++)
				f[j][i]=a[j+(i-1)*n];
		else
			for(j=1;j<=n;j++)
				f[j][i]=a[i*n-j+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) if(f[i][j]==r){
			cout<<j<<" "<<i;
			return 0;
		}
	return 0;
}