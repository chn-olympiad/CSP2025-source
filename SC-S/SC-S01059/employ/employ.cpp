#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],kk;
bool s[505];
long long ans=1ll;
char ch;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	kk=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		if(!c[i])
		{
			kk--;
		}
	}
	if(kk<m)return !printf("0");
	for(int i=kk;i>1;i--)(ans*=1ll*i)%=998244353ll;
	printf("%lld",ans%998244353ll);
	return 0;
}
/*
3 2
101
1 1 2

*/