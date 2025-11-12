#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans=0,sum=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=i;
		for(int j=i+1;j<=n;j++)
		{//一位一位异或 
			if(ans==k)
			{
				sum++;
				i=j+1;
				ans=i; 
				break;
			}
			ans^=j;
		}
	}
	cout<<sum;
	return 0;
}//0分---10分 
