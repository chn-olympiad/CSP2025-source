#include<bits/stdc++.h>
using namespace std;
int n,k,an=0,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int r=i;r<n;r++)
		{
			an=an|a[r];
			if(an==k)
			{
				ans++;
				i=r;
				an=0;
				break;
			}		
		}	
	}
	cout<<ans;
	return 0;	
}
