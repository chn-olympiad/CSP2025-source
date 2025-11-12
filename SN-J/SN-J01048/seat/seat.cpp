#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[105],r,rw;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==r){
			rw=i;break;
		}
	}rw=(n*m)-rw;
	ll l=rw/n+1,h=rw%n+1;
	if(l%2==0)h=n+1-h;
	cout<<l<<" "<<h<<endl;
	return 0;
}
