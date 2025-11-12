#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+4;
int n,m;
long long ans=1;
void init()
{
	scanf("%d%d",&n,&m);
	string s;
		cin>>s;
	for(int i=1;i<=n;i++)
	{
		int c;
		scanf("%d",&c);
	}
}
void slove()
{
	for(int i=n;i>=2;i--)
		ans=ans*i%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	slove();
	ans%=998244353;
	printf("%lld",ans);
}

