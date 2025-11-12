#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505];
string s;
long long jc(int n)
{
	register long long sum=1;
	for(int i=2;i<=n;i++)
		sum=sum*i%mod;
	return sum;
}
int main()
{
	freopen("employ.in","r",stdin);
//	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	if(s.find("0")==string::npos)
		printf("%lld",jc(n)),exit(0);
	return 0;
}
