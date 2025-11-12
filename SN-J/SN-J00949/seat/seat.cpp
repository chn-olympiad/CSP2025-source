#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100],s,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
	s=a[0],sort(a,a+n*m),s=lower_bound(a,a+n*m,s)-a;
	s=n*m-s,s--,l=(s+1)/n;
	if((s+1)%n)l++;
	if(l&1)printf("%d %d",l,(s+1)-(l-1)*m);
	else printf("%d %d",l,l*m-s);
	return 0;
}
