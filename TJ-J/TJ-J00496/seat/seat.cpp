#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=105;
int n,m;
struct node{
	int id,val;
	bool operator<(const node &o)const{
		return val>o.val;
	}
}a[N];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n*m+1);
	int cnt=1;
	for(;cnt<=n*m;cnt++){
		if(a[cnt].id==1)break;
	}
	int c=cnt/n+(cnt%n!=0),r;
	if(c&1){
		if(cnt%n==0)r=n;
		else r=cnt%n;
	}else{
		if(cnt%n==0)r=1;
		else r=n-(cnt%n)+1;
	}
	cout<<c<<' '<<r<<'\n';
	return 0;
}

