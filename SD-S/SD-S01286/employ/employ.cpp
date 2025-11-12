#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,n,nn,m;
	string s;
	cin>>n>>m;
	cin>>s;
	nn=n;
	for(int i=1;i<=nn;i++)
	{
		cin>>a;
		if(a==0)  n--;
	}
	int cha=n-m;
	long long nj=1,mj=1,nmj=1; 
	for(int i=n;i>1;i--)
	{
		
		nj*=i;
		nj=nj; 
	}
	for(int i=cha;i>1;i--)
	{
		nmj*=i;
		nmj=nmj;
	 } 
	long long ans=nj/nmj;
	cout<<ans;
	return 0;
}
