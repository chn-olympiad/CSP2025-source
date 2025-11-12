#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[11000]={0};
	scanf("%d%d",&n,&k);
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum^=a[i]; 
	}
	printf("%d",sum);
	return 0;  
}
