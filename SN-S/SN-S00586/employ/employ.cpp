#include<bits/stdc++.h>
using namespace std;
 
int n,m;
string s;
int c[505];
int mod=998244353;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	int ans=1;
	for(int i=2;i<=n;i++)
		ans=(ans*i)%mod;
	printf("%d",ans);

		
	return 0;
}


