#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10010;
int n,m,i,id;
struct no{int x,id;}a[N];
bool cmp(no q,no h){return q.x>h.x;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i].id==1) break;
	id=i;
	if(id%n==0) cout<<id/n<<" ";
	else cout<<id/n+1<<" ";
	if(id%(n*2)==0) cout<<1;
	else if(id%(n*2)<=n) cout<<id%(n*2);
	else if(id%(n*2)>=n) cout<<n+1-id%n;
	return 0;
}
