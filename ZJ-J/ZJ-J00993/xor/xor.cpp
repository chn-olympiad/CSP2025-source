#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
			else if(a[i]==1 && a[i+1]==1)
			{
				i++;
				cnt++;
			}
		}
		cout<<cnt;
	}
	else if(k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}