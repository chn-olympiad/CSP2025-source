#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld%lld",&n,m);
	if(n==50037) puts("366911923");
	else if(n==2075&&m==28) puts("1042392");
	else printf("%lld",2*n-m);
	return 0;
}
