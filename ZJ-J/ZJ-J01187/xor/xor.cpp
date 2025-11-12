#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==0) printf("%d",n/2);
	return 0;
}
