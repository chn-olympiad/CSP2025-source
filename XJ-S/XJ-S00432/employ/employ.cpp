#include<bits/stdc++.h>
using namespace std;
long long int c[1000005];
string s[1000005];
int main()
{
	long long int i,j,m,n,ans=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	cin>>s[i];
	for(i=1;i<=n;i++)	
	cin>>c[i];	
	if(m==n)
	{
	for(i=1;i<=n;i++)
	if(s[i]=="0"||c[i]==0)	
	{
	cout<<0;	
	return 0;	
	}	
	ans=1;
	for(i=1;i<=n;i++)
	ans*=i;
	cout<<ans%998;
	cout<<ans%244;
	cout<<ans%353;
	return 0;	
	}
	return 0;
}
