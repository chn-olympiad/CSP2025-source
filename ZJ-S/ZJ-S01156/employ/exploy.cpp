#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],sum=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
srand(time(NULL));
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)sum=sum*(!c[i]?rand()%(n*m*m):c[i])%998244353;
	printf("%lld",sum);
	return 0;
}