#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110],t,cnt,f;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;++i)
	scanf("%lld",&a[i]);
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;--i){
		++cnt;
		if(a[i]==t)break;
	}
	f=cnt/n;
	if(f*n==cnt){
		if(f%2==1)printf("%lld %lld",f,n);
		else printf("%lld %lld",f,1);
	}
	else{
		if(f%2==0)printf("%lld %lld",f+1,cnt-f*n);
		else printf("%lld %lld",f+1,n-(cnt-f*n)+1);
	}
}