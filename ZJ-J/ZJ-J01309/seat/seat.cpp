#include<bits/stdc++.h>
using namespace std;
const long long N=20;
long long n,m,a[N*N],cnt,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&a[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if(a[i]>a[1])
		cnt++;
	}
	cnt++;
	l=(cnt+n-1)/n;
	r=cnt-(l-1)*n;
	if(l%2==1)
	printf("%lld %lld",l,r);
	else
	printf("%lld %lld",l,n-r+1);
	return 0;
}
