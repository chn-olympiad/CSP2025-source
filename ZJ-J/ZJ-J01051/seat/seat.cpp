#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=101;
int n,m;
struct Node {
	int v,id;
} a[maxn];
int cmp(Node x,Node y) {
	return x.v>y.v;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i].v,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	int now;
	for(int i=1; i<=m*n; i++) {
		if(a[i].id!=1) continue;
		now=i;
		break;
	}
	int tmp=(now-1)/n+1;
	now-=(tmp-1)*n;
	cout<<tmp<<" ";
	if(tmp&1) cout<<now;
	else cout<<n-now+1;
	return 0;
}