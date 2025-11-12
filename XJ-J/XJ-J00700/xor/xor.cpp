#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int maxn=0,n,k;
	int a;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>maxn)
		maxn=a;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
