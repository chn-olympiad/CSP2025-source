#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,i,sx,sy,x,f,xh,a[110];
bool cmp(int q,int h){return q>h;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;s=n*m;
	for(i=1;i<=s;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+s+1,cmp);
	for(i=1;i<=s;i++)
		if(x==a[i])
			xh=i;
	sx=(xh+n-1)/n;
	if(sx%2==1) sy=xh-(sx-1)*n;
	else sy=n-(xh-(sx-1)*n)+1;
	cout<<sx<<" "<<sy;
}
