#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000003],ans;
bool ax[1000003];
int shu(int i,int j)
{
	int sum=0;
	for(int r=i+1;r<=j;r++)
	{
		int c = a[r];
		for(int x=r+1;x<=j;x++)
		{
			c = c xor a[x];
			if(c == k)
			{
				sum++;	
				r = x;				
			}
		}
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long cnt;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ax[i] = true;
		if(a[i] == k)
		{
			ans++;
			ax[i] = false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int c = a[i];
		if(!ax[i])
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if(!ax[j])
			{
				ax[i] = false;
				break;
			}
			c = c xor a[j];
			if(c == k)
			{
				if(shu(i,j)<=1)
					i = j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}