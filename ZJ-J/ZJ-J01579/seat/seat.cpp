#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,cnt,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		int b;cin>>b;
		if(b>a) cnt++;
	}
	y=cnt/n;
	if(y&1) x=n-(cnt-y*n);
	else x=cnt-y*n+1;
	cout<<y+1<<" "<<x;
	return 0;
}

