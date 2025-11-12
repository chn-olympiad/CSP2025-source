#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000100],b[1000100],f[4000100],ans;
int main( )
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	f[0]=1;
	long long l=1;
	for(int i=1;i<=n;i++)
	{
		long long s=b[i]^b[l-1];
		long long s1=s^k;
		if(f[s1]==1)
		{
			ans+=1;
			for(int j=i-1;j>=l;j--)
			{
				long long s2=b[j]^b[l-1];
				f[s2]=0;
			}
			f[0]=1;
			l=i+1;
		}
		else
		{
			f[s]=1;
		}
	}
	cout<<ans;
	return 0;
}
//bie gua fen bie gua fen
//I LOVE BYM   QwQ
