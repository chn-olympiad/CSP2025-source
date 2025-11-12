#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<'0';
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
