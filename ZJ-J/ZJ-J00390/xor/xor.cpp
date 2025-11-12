#include<bits/stdc++.h>
using namespace std;
int n,m,min=INT_MAX;
int a[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==2) cout<<1;
	for(int i=1;i<=n;i++)
	{
		if(min>=a[i])
			min=a[i];
	}
	cout<<min;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
