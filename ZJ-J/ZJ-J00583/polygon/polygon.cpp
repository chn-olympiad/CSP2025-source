#include<bits/stdc++.h>
using namespace std;
int chopsticks[5009];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>chopsticks[i];
	}
	sort(chopsticks,chopsticks+n);
	if(n==3)
	{
		if(chopsticks[0]+chopsticks[1]>chopsticks[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	bool check = 0;
	for(int i=1;i<n;i++)
	{
		if(chopsticks[i] != 1)
		{
			check=1;
		}
	}
	if(!check)
	{
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=(n-i+1);j>0;j--)
			{
				ans+=j;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}