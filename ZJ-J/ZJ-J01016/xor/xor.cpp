#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],ans;
bool fa=true,fb=true;
void ab()
{
	if(k==0&&fa)
	{
		cout<<n/2;
	}
	else if(k==0&&fb)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1)
			{
				i++;
				ans++;
			}
		}
		cout<<ans;
	}
	else if(k==1&&fb)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)fa=false;
		if(a[i]!=0&&a[i]!=1)fb=false;
	}
	if(fa||fb)
	{
		ab();
		return 0;
	}
	return 0;
}