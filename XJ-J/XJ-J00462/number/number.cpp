#include<bits/stdc++.h>
using namespace std;
const int N=1e6+111;
int a[N],nu;
char s[N];
int main()
{
	FILE* aa=fopen("number.in","r");
	FILE* ab=fopen("number.out","w");
	fscanf(aa,"%s",s); 
	//scanf("%s",s);
	int n=strlen(s);
	if(n==1)
	{
		//printf("%s",s);
		fprintf(ab,"%s\n",s);
		return 0; 
	}
//	printf("%d ",n); 
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			nu++;
			a[nu]=s[i]-'0';
		//	printf("%d ",a[nu]);
		}
	}
//	for(int i=1;i<=nu;i++)
//	{
//		printf("%d",a[i]);
//	}
//	printf(" ");
	for(int i=0;i<nu;i++)
	{
		for(int j=i;j<nu;j++)
		{
			if(a[i]<a[j]&&i!=j )
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<nu;i++)
	{
		//printf("%d",a[i]);
		fprintf(ab,"%d",a[i]);
	}
	fclose(aa);
	fclose(ab);
	return 0;
}
