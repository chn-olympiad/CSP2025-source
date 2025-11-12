#include<bits/stdc++.h>
using namespace std;
const int N=1e6+111;
int a[N],human,n,m;
int main()
{
	FILE* aa=fopen("seat.in","r");
	FILE* ab=fopen("seat.out","w");
	fscanf(aa,"%d%d",&n,&m);
//	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		//scanf("%d",&a[i]);
		fscanf(aa,"%d",&a[i]);
	}
	human=a[1];	
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=m*n;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	int tu;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==human)
		{
			tu=i;
		}
	}
	int nu=0;
	if(m%2==0)
	{
		for(int i=1;i<=m/2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				nu++;
				if(nu==tu)
				{
					//printf("%d %d",i,j);
					fprintf(ab,"%d %d\n",i,j);
					return 0;
				}
			}
			i++;
			for(int j=n;j>=1;j--)
			{
				nu++;
				if(nu==tu)
				{
					//printf("%d %d",i,j);
					fprintf(ab,"%d %d\n",i,j);
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(i==m/2+1 )
			{
				
				for(int j=1;j<=n;j++)
				{
					nu++;
					if(nu==tu)
					{
						//printf("%d %d",i,j);
						fprintf(ab,"%d %d\n",i,j);
						return 0;
					}
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					nu++;
					if(nu==tu)
					{
						//printf("%d %d",i,j);
						fprintf(ab,"%d %d\n",i,j);
						return 0;
					}
				}
				i++;
				for(int j=n;j>=1;j--)
				{
					nu++;
					if(nu==tu)
					{
					//	printf("%d %d",i,j);
						fprintf(ab,"%d %d\n",i,j);
						return 0;
					}
				}
			//	printf("%d %d %d",nu,i,m/2+1);
			}
			
		}

}
	return 0;
}

