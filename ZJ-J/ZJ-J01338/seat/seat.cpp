#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,r;
int a[105];
int p[105][105];
bool cmp(int x,int y){
	return x>y;
}
int pos=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;++i){
		if(i&1)for(int j=1;j<=n;++j)p[j][i]=a[pos++];
		else for(int j=n;j>=1;--j)p[j][i]=a[pos++];
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(p[i][j]==r){
		cout<<j<<' '<<i;
		return 0;
	}
	return 0;
}
