#include<bits/stdc++.h>
using namespace std;
const int N=1e6+111;
int a[N],human,n,m;
int main()
{

	FILE* aa=fopen("xor.in","r");
	FILE* ab=fopen("xor.out","w");
	fscanf(aa,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		fscanf(aa,"%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	} 
//	for(int i=1;i<=n;i++) 
//	{
//		printf("%d",a[i]);
//	}
	fprintf(ab,"%d",a[n-m]);
	return 0;
}

