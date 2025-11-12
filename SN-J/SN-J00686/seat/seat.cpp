//SN-J00686  汤佳忆  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e4+5;
bool cmp(int a,int b) {
	return a>b;
}
int n,m,a[MAXN],nm,xiaoming,b[1005][1005],jsq=1,xx,yy;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1; i<=nm; i++) cin>>a[i];
	xiaoming=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2!=0) {
			for(int j=1; j<=n; j++) {
				if(a[jsq]==xiaoming) yy=j,xx=i;
				b[i][j]=a[jsq];
				jsq++;
			}
		} else {
			for(int j=n; j>=1; j--) {
				if(a[jsq]==xiaoming) yy=j,xx=i;
				b[i][j]=a[jsq];
				jsq++;
			}
		}
	}
	cout<<xx<<" "<<yy;
	return 0;
}
