#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[110],mp[20][20];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1],d;
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		if(a[i]==k){
			d=t-i+1;
			break;
		}
	}
	int x,y=1;
	if(d<=n){
		cout<<d<<' '<<1;
		return 0;
	}
	while(d>=n) d-=n,y++;
	if(y%2!=0){
		x=d;
	}else{
		x=n-d+1;
	}
	cout<<y<<' '<<x;
	return 0;
}
