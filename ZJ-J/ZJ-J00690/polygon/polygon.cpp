#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxl,all;
long long solve()
{
	if(n<3) return 0;
	if(all>maxl*2) return 1;
	return 0;	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxl=max(maxl,a[i]);
		all+=a[i];
	}
	cout<<solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
