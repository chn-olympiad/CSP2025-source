#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],k,id;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;++i)
	  cin>>a[i],a[i]=-a[i];
	k=a[1];
	sort(a+1,a+1+n*m);
	id=lower_bound(a+1,a+1+n*m,k)-a;
	cout<<(id-1)/n+1<<" "<<min(id%(2*n),n*2-id%(2*n)+1);
	return 0;
}