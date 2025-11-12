#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
int n,m,k;
int p,q;
struct node {
	int num;
	bool f;
}a[N];
bool cmp(node x,node y) {
	return x.num>y.num;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].num;
	a[1].f=true;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i].f==true) {
			k=i;
			break;
		}
	}
	q=k%n;
	p=(k-q)/n;
	if(p%2==0) {
		if(q==0) {
			cout<<p<<" "<<1<<"\n";
		}
		else cout<<p+1<<" "<<q<<"\n";
	}
	else {
		if(q==0) {
			cout<<p<<" "<<m<<"\n";
		}
		else cout<<p+1<<" "<<n-q+1<<"\n";
	}
	return 0;
}
