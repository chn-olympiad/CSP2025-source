#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[110],b[11][11],j,xr,pm,t;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=m*n;i++)
		if(a[i]==xr){
			pm=i;break;
		}
	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=m;j++)
				b[i][j]=++t;
			}
			else{
				for(j=m;j>=1;j--)
					b[i][j]=++t;
			}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(pm==b[i][j]){
				cout<<i<<" "<<j;return 0;
			}
	return 0;
}

