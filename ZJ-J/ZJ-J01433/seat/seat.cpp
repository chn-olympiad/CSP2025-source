#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[205],idm,r=1,c=1;
bool flag=false;
bool cmp(int x,int y)
{
	if(x>y) return true;
	return false;
}
signed main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	idm=a[1];
	sort(a+1,a+n*m+1,cmp);
//	if(a[1]==idm){
//		printf("%lld %lld",c,r);
//		return 0;
//	}
//	for(int i=1;i<=n*m;i++) printf("%lld ",a[i]);
//	printf("\n");
	for(int i=1;i<=n*m;i++){
		if(a[i]==idm){
			printf("%lld %lld",c,r);
			return 0;
		}
		if(!flag) r++;
		else r--;
		if(r>n) c++,r--,flag=true;
		if(r<1&&i!=1) c++,r++,flag=false;
	}
	return 0;
}
