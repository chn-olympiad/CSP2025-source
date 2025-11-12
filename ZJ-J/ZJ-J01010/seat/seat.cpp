#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,s[1005],cj;
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++) scanf("%lld",&s[i]);
	cj=s[1];sort(s+1,s+n*m+1,greater<int>());
	for(ll i=1;i<=n*m;i++) if(s[i]==cj) {cj=i;break;}
	if(((cj-1)/n)%2==0) printf("%lld %lld",(cj-1)/n+1,(cj-1)%n+1);
	else printf("%lld %lld",(cj-1)/n+1,n-((cj-1)%n+1)+1);
	return 0;
}
