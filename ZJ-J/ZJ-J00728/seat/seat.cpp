#include<bits/stdc++.h>
using namespace std;
int n,m,b[15][15],cnt;
struct zk{
	int s,id;
}a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].s,a[i].id=i;
	sort(a+1,a+1+n*m,[](const zk &A,const zk &B){
		return A.s>B.s;
	});
	int i=1,j=1;
	for(int k=1;k<=m/2;k++){
		for(;i<=n;i++)b[i][j]=a[++cnt].id;
		j++,i=n;
		for(;i>=1;i--)b[i][j]=a[++cnt].id;
		j++,i=1;
	}
	if(m&1)for(i=1;i<=n;i++)b[i][j]=a[++cnt].id;
	int r,c;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)if(b[i][j]==1){r=i,c=j;break;}
	cout<<c<<' '<<r;
	return 0;
}
