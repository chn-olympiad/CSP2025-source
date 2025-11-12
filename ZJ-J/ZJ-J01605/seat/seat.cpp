#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1001][1001],b[1000001],c[1001][1001],w,h,l,t;
bool cmp(int t,int w){
	return t>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)cin>>a[i][j],b[++t]=a[i][j];
	sort(b+1,b+1+t,cmp);
	w=1;h=1;l=1;
	while(w<=t){
		c[h][l]=b[w];
		if(h%2==1){
			l++;
			if(l==m+1)l=m,h++;
		}
		else{
			l--;
			if(l==0)l=1,h++;
		}
		w++;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(c[i][j]==a[1][1]){
				cout<<i<<" "<<j;
			}
	return 0;
}
