#include<bits/stdc++.h>
using namespace std;
int nums[500002];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	bool  x=0;
	for(int i=0;i<n;i++)
	{
		if(nums[i]!=1)
		{
			x=1;
		}
	}
	if(!x)
	{
		cout<<(n/2);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
