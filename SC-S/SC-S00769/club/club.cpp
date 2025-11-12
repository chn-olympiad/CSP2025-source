#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
int t,club[10001][3],record[10001],l1=0,l2=0,l3=0,s=0;
int n;
int main()
{
	fin=fopen("club.in","r");
	fout=fopen("club.out","w");
fscanf(fin,"%d",t);
for(int z=1;z<=t;z++)
{

fscanf(fin,"%d",n);
for(int p=1;p<=10000;p++)
		{
			for(int q=1;q<=3;q++)
			{
				club[p][q]=0;
			}
		}
		for(int p=1;p<=10000;p++)
		record[p]=0;
		l1=0;l2=0;l3=0;s=0;
		for(int je=1;je<=n;je++)
		{
			fscanf(fin,"%d",club[je][1]);
			fscanf(fin,"%d",club[je][2]);
			fscanf(fin,"%d",club[je][3]);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(max(max(club[i][1],club[i][3]),max(club[i][2],club[i][3]))==club[i][1])
			{
			record[i]=1;
			l1++;
			}
			if(max(max(club[i][1],club[i][3]),max(club[i][2],club[i][3]))==club[i][2])
			{
			record[i]=2;
			l2++;
			}
			if(max(max(club[i][1],club[i][3]),max(club[i][2],club[i][3]))==club[i][3])
			{
			record[i]=3;
			l3++;
			}
			
				int pd=1;
			if(record[i]==1&&l1>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					if(record[j]==1)
					{
					pd=0;
						if(max(club[j][2],club[j][3])>=max(club[j][2],club[j][3]))
						{
							if(club[j][2]>=club[j][3]&&l2<n/2)
							{
								record[j]=2;
								l2++;
							}
							else
							{
								record[j]=3;
								l3++;
							}
							pd=1; 
							break;
						}
					}
				if(pd==0)
				{
					if(club[j][2]>club[j][3]&&l2<n/2)
					{
						record[i]=2;
						l2++;
					}
					else
					{
						record[i]=3;
						l3++;
					}
				}
				}
			}
			
			
			
			if(record[i]==2&&l2>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					if(record[j]==2)
					{
					pd=0;
						if(max(club[j][1],club[j][3])>=max(club[j][1],club[j][3]))
						{
							if(club[j][1]>=club[j][3]&&l1<n/2)
							{
								record[j]=1;
								l1++;
							}
							else
							{
								record[j]=3;
								l3++;
							}
							pd=1; 
							break;
						}
					}
				if(pd==0)
				{
					if(club[j][1]>club[j][3]&&l1<n/2)
					{
						record[i]=1;
						l1++;
					}
					else
					{
						record[i]=3;
						l3++;
					}
				}
				}
			}
			
			
			if(record[i]==3&&l3>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					if(record[j]==3)
					{
					pd=0;
						if(max(club[j][1],club[j][2])>=max(club[j][1],club[j][2]))
						{
							if(club[j][1]>=club[j][2]&&l1<n/2)
							{
								record[j]=1;
								l1++;
							}
							else
							{
								record[j]=2;
								l2++;
							}
							pd=1; 
							break;
						}
					}
				if(pd==0)
				{
					if(club[j][1]>club[j][2]&&l1<n/2)
					{
						record[i]=1;
						l1++;
					}
					else
					{
						record[i]=2;
						l2++;
					}
				}
				}
			}
			
			
			
		}
		for(int i=1;i<=n;i++)
		{
		s=s+club[i][record[i]];
		}
		fprintf(fout,"%d\n",s);
	}
	return 0;
} 