#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0,w=-1;
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(a[i]^s[i-1]);
		for(int j=w+1;j<=i-1;j++)
		{
			if((s[i]^s[j])==k)
			{
				ans++;
				w=j;
				break;
			}
		}
	}
	cout<<ans;



	return 0;
}