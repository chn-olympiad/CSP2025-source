#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int Mod=998244353;
const int N=1e3;
int n,m;
int a[N],c[N],b[N];
string s;
ll Pow(int num)
{
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=Mod;
	}
	return ans;
}
void putsB()
{
	for(int i=0;i<=n-1;i++)
		if(s[i]=='0')
		{
			printf("0\n");
			return ;
		}
	ll k=Pow(n);
	printf("%lld\n",k);
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n==m) putsB();
		else cout<<Pow(n)<<"\n";
	return 0;
 } 
