#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int jc(int x)
{
	int cj=1;
	for(int i=1;i<=x;i++)
	{
		cj*=i;
	}
	return cj;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<jc(n)/jc(n-3)%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
