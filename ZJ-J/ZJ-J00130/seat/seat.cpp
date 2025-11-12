#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,y,x,c,r,cnt=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x) cnt++;
	}
	c=(cnt-1)/n+1;
	r=cnt-(c-1)*n;
	if(c%2==0) r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
