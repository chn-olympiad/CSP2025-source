#include<bits/stdc++.h>
using namespace std;
long long a[10010][5050],b[5050];
bool vet[5050][5050];
long long n;
struct node
{
	long long shu;
	long long i;
	long long j;
}mi[10010];

bool jfan(int j)
{
	int j1=0,j2=0,j3=0;
	if(j==1)
	{
		j1++;
		if(j1*2>n)
		{
			return true;
		}
	}
	else if(j==2)
	{
		j2++;
		if(j2*2>n)
		{
			return true;
		}
	}
	else if(j==3)
	{
		j3++;
		if(j3*2>n)
		{
			return true;
		}
	}
	return false;
}
void dfs()
{
	int j1=1,j2=0,shu=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3])) && vet[i][1]==0)
			{
				mi[i].shu=a[i][1];
				mi[i].i=i;
				mi[i].j=1;
				vet[i][1]=1;
			}
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3])) && vet[i][2]==0)
			{
				mi[i].shu=a[i][2];//1
				mi[i].i=i;//1
				mi[i].j=2;
				vet[i][2]=1;
			} 
			else if(a[i][3]==max(a[i][1],max(a[i][2],a[i][3])) && vet[i][3]==0)
			{
				mi[i].shu=a[i][3];
				mi[i].i=i;
				mi[i].j=3;
				vet[i][3]=1;
			}
			if(j2==1 && vet[i][1]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[2];
				mi[i].i=i;
				
				if(a[i][1]==b[2] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[2] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[2] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 } 
				
			}
			else if(j2==2 && vet[i][2]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[2];
				mi[i].i=i;
				
				if(a[i][1]==b[2] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[2] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[2] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 } 
				
			}
			else if(j2==3 && vet[i][3]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[2];
				mi[i].i=i;
				
				if(a[i][1]==b[2] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[2] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[2] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 } 
				
			}
			if(j2==1 && vet[i][1]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[1];
				mi[i].i=i;
				
				if(a[i][1]==b[1] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[1] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[1] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 } 
				
			}
			else if(j2==2 && vet[i][1]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[1];
				mi[i].i=i;
				
				if(a[i][1]==b[1] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[1] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[1] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 }
				
			}
			else if(j2==3 && vet[i][1]==1)
			{
				b[1]=a[i][1];
				b[2]=a[i][2];
				b[3]=a[i][3];
				sort(b+1,b+n+1);
				mi[i].shu=b[1];
				mi[i].i=i;
				
				if(a[i][1]==b[1] && vet[i][1]==0)
				{
					vet[i][1]=1;
					mi[i].j=1;
				 } 
				else if(a[i][2]==b[1] && vet[i][2]==0)
				{
					vet[i][2]=1;
					mi[i].j=2;
				 } 
				 else if(a[i][3]==b[1] && vet[i][3]==0)
				{
					vet[i][3]=1;
					mi[i].j=3;
				 } 
				
			}
			
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=3;j++)
		{
			//cout<<mi[i].j<<" ";
			if(jfan(mi[i].j))
			{
				j2=mi[i].j;
				//cout<<j2<<" ";
				dfs();
			}	
		}
			
	}
	for(int i=1;i<=n;i++)
	{
		shu+=mi[i].shu;
	}
	cout<<shu;
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs();
	}
	
	
	return 0;
 } 
 
 /*
4
4 2 1
3 2 4
5 3 4
3 5 1

4
1 0 0
0 1 0
0 2 0
0 2 0
*/
