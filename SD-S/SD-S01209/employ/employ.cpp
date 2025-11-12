#include<iostream>
#include<cstdio> 
#include<cstring> 
using namespace std;
int c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,mod=998244353;
	long long ans=1;
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	  scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	  ans=ans*i%mod; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
