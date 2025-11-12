#include<bits/stdc++.h>
#define ll long long
#define P 998244353
using namespace std;
const int N=1007;
int n,m,pat[N],lis[N];
char s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	bool special_A=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pat[i]);
		lis[i]=i;
		if(s[i]-'0'==0)
			special_A=false;
	}
//	if(special_A)
//	{
//		ll ans=1;
//		for(int i=1;i<=n;i++)
//		{
//			ans=ans*i%P;
//		}
//		printf("%lld",ans);
//		fclose(stdin);
//		fclose(stdout);
//		return 0;
//	}
	int ans=0;
	do
	{
		int fail=0,cttn=0;
		for(int i=1;i<=n;i++)
		{
			if(fail>=pat[lis[i]])
			{
				fail++;
				continue;
			}
			if(s[i]=='1')
				cttn++;
			else
				fail++;
		}
		if(cttn>=m)
			ans++;
	}while(next_permutation(lis+1,lis+1+n));
	printf("%d",ans%P);
	fclose(stdin);
	fclose(stdout);
	return 0;
}