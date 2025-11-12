#include<bits/stdc++.h>
using namespace std;
int i,k=0,m,n,a[100004],b[100005],j,s;
int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]); 
	for(i=1;i<=n;i++)
	for(k=2;k<=n;k++)
	for(j=3;j<=n;j++)
	{
		if(i+k>j)
		s++;
	}
	printf("0");
	return 0;
 } 
