#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],s,b[200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			s++;
			b[i]=1;
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0 && b[i+1]==0)
			{
				s++;
				b[i]=1;
				b[i+1]=1;
			}
		}
		cout<<s;
	}
	else
		cout<<s;
	return 0;
}
