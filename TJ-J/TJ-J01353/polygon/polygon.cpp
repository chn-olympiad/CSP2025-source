#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int li[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&li[i]);
	}
	printf("%d",n/2+n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
