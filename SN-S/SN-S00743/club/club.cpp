#include<bits/stdc++.h>
using namespace std;

struct people
{
	int nm;
	int dx=10000000; 
}p1[100005];
people p2[100005];
people p3[100005];

int t;
int n,a[100005][4]={};
int b[4]={},s;

bool cmp(people h,people u)
{
	return h.dx<=u.dx;
}

int chaofou(int d,int r)
{
	if(b[d]<n/2)
	{
		b[d]++;
		return -1;
	}
	else
	{
		int f;
		if(d==1)
		{
			sort(p1+1,p1+1+r,cmp);
			if(a[p1[1].nm][2]>a[p1[1].nm][3])
			{
				f=2;
			}
			else
			{
				f=3;
			}
			if(a[p1[1].nm][f]+a[r][d]>a[p1[1].nm][d])
			{	
				if(f==2)
				{
					p2[r].dx=a[p1[1].nm][f];
					p2[r].nm=p1[1].nm;
				}
				else
				{
					p3[r].dx=a[p1[1].nm][f];
					p3[r].nm=p1[1].nm;
				}
				
				s-=a[p1[1].nm][d];
				s+=a[p1[1].nm][f];
				s+=a[r][d];
				p1[1].dx=a[r][d];
				p1[1].nm=r;
				b[f]++;
			}
			else
			{
				int g;
				if(a[r][2]>a[r][3])
				{
					g=2;
					p2[r].dx=a[r][g];
					p2[r].nm=r;
				}
				else
				{
					g=3;
					p3[r].dx=a[r][g];
					p3[r].nm=r;
				}
				s+=a[r][g];
				b[g]++;
			}
			
		}
		else if(d==2)
		{
			sort(p2+1,p2+1+r,cmp);
			if(a[p2[1].nm][1]>a[p2[1].nm][3])
			{
				f=1;
			}
			else
			{
				f=3;
			}
			if(a[p2[1].nm][f]+a[r][d]>a[p2[1].nm][d])
			{	
				if(f==1)
				{
					p1[r].dx=a[p2[1].nm][f];
					p1[r].nm=p2[1].nm;
				}
				else
				{
					p3[r].dx=a[p2[1].nm][f];
					p3[r].nm=p2[1].nm;
				}
				
				s-=a[p2[1].nm][d];
				s+=a[p2[1].nm][f];
				s+=a[r][d];
				p2[1].dx=a[r][d];
				p2[1].nm=r;
				b[f]++;
			}
			else
			{
				int g;
				if(a[r][1]>a[r][3])
				{
					g=1;
					p1[r].dx=a[r][g];
					p1[r].nm=r;
				}
				else
				{
					g=3;
					p3[r].dx=a[r][g];
					p3[r].nm=r;
				}
				s+=a[r][g];
				b[g]++;
			}
		}
		else if(d==3)
		{
			sort(p3+1,p3+1+r,cmp);
			if(a[p3[1].nm][1]>a[p3[1].nm][2])
			{
				f=1;
			}
			else
			{
				f=2;
			}
			if(a[p3[1].nm][f]+a[r][d]>a[p3[1].nm][d])
			{	
				if(f==1)
				{
					p1[r].dx=a[p3[1].nm][f];
					p1[r].nm=p3[1].nm;
				}
				else
				{
					p2[r].dx=a[p3[1].nm][f];
					p2[r].nm=p3[1].nm;
				}
				
				s-=a[p3[1].nm][d];
				s+=a[p3[1].nm][f];
				s+=a[r][d];
				p3[1].dx=a[r][d];
				p3[1].nm=r;
				b[f]++;
			}
			else
			{
				int g;
				if(a[r][1]>a[r][2])
				{
					g=1;
					p1[r].dx=a[r][g];
					p1[r].nm=r;
				}
				else
				{
					g=2;
					p2[r].dx=a[r][g];
					p2[r].nm=r;
				}
				s+=a[r][g];
				b[g]++;
			}
		}
		return 0;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		for(int j=1;j<=3;j++)
		{
			b[j]=0;	
		}
		s=0; 
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
		 	int m=1;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][m]<a[i][j])
				{
					m=j;
				}	
			}
			if(chaofou(m,i)==-1)
			{
				s+=a[i][m];
				if(m==1)
				{
				p1[i].dx=a[i][m];
				p1[i].nm=i;	
				}
				else if(m==2)
				{
				p2[i].dx=a[i][m];
				p2[i].nm=i;	
				}
				else if(m==3)
				{
				p3[i].dx=a[i][m];
				p3[i].nm=i;	
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
