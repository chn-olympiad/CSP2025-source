#include<bits/stdc++.h>
using namespace std;

const int maxn=15*15;
int n,m,a[maxn],nw,x=1,y=1;
void chg(){
	if(y&1){
		if(x==n) ++y;
		else ++x;
	}
	else{
		if(x==1) ++y;
		else --x;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	nw=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==nw){
			cout<<y<<' '<<x<<'\n';
			return 0;
		}
		chg();
	}
	return 0;
}
