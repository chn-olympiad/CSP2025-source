#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],t,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	w=lower_bound(a+1,a+1+n*m,t)-a;
	w=n*m-w+1;
	t=(w-1)%(2*n)+1;
	cout<<(w-1)/n+1<<" "<<(t>n?n*2-t+1:t);
	return 0;
}
