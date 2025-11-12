#include<bits/stdc++.h>
using namespace std;
long long su[500005],n,a,an,ar;
unsigned long long k;
bool v[500005]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		su[i]^=a;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]) continue;
		if(su[i]==k)
		{
			an++;
			v[i]=1;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(v[j]) continue;
			if((su[i]^su[j])==k)
			{
				an++;
				for(int k=i;k<=j;k++)
				{
					v[k]=1;
				}
				continue;
			}
		}
	}
	cout<<an;
	return 0;
} 
/*
*/
