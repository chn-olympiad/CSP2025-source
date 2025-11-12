#include<iostream>
using namespace std;
char s[505];
int n,m,i,j,k=998244353,c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int l=0,ans=1;
	for(i=1;i<=n;i++)
	{
		ans=ans*(n-l);
	}
	ans=ans%k;
	cout<<ans;
	return 0;
 } 
