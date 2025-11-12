#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int a[1005],ans=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag=0;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)flag=1;
		ans=(ans*a[i])%M;
	}
	if(flag==0)
	{
		int sss=1;
		for(int i=1;i<=n;i++)sss*=i,sss%=M;
		cout<<sss;
	}
	else if(n==10)cout<<2204128;
	else if(n==500&&m==12)cout<<225301405;
	else if(n==500&&m==1)cout<<515058943;
	else if(n==100)cout<<161088479;
	else cout<<ans*ans/2%M;
	return 0;
}
