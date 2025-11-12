#include<bits/stdc++.h>
using namespace std;
int a[600001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,bi=0,bj=0,cnt1=0,cnt2=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			if(a[i]==0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
	}
	if(cnt1==0 && cnt2==0)
	{
		cout<<n/2;
		return 0;
	}
	else if(cnt1!=0 && cnt2==0)
	{
		cout<<n/2;
	}
	return 0;
} 
