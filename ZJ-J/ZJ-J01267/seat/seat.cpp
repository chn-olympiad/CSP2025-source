#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[10010],z,id,b[110][110],j,tot;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	z=a[1];sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i]==z) id=i;
	for(i=1;i<=m;i++)
		if(i%2==1){
			for(j=1;j<=n;j++) b[j][i]=++tot;
		}
		else{
			for(j=n;j>=1;j--) b[j][i]=++tot;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]==id){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}