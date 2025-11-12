#include<bits/stdc++.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n, m;
	long long int ans = 0;
	scanf("%d%d",&n,&m);
	char s[n];
	scanf("%s", &s);
	int flag = 1;
//	for(int i = 0; i < n; i++)
//	{
//		if(s[i]=='1')flag = 1;
//	}
	if(flag)
	{
		ans = 1;
		for(int i = 1; i <= n; i ++)
		{
			ans = (i*ans)%998244353;
		}
	}
	printf("%d", ans%998244353);
	
	return 0;
}
