#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int pos=0;
	int i=1;
	while(i<=n)
	{
		int sum=0;
		bool f=false;
		for(int j=i;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				ans++;
				pos=j;
				f=true;
				break;
			}
		}
		if(f)i=pos+1;
		else i++;
	}
	cout<<ans;
}
