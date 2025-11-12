#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		int n=0,a[50000][4],b[50000],l1[50000],l2[50000],l3[50000],h=0,n1=0,n2=0,n3=0,z1=-1,z2=-1,z3=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(max(a[i][1],a[i][2])==a[i][1]&&max(a[i][1],a[i][3])==a[i][1])
			{
				h+=a[i][1];
				n1++;
				l1[n1]=i;
			}
			else
			{
				if(max(a[i][1],a[i][2])==a[i][2]&&max(a[i][2],a[i][3])==a[i][2])
				{
					h+=a[i][2];
					n2++;
					l2[n2]=i; 
				}
				else
				{
					if(max(a[i][1],a[i][3])==a[i][3]&&max(a[i][2],a[i][3])==a[i][3])
					{
						h+=a[i][3];
						n3++;
						l3[n3]=i;
					}	
				}
			}	
		}
		if(n1>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]); 
				if(b[i]<0)
				{
					b[i]=b[i]/(-1);
				}
			} 
			sort(b+1,b+1+n);
			for(int i=1;i<=n1-n/2;i++)
			{
				h=h-b[i];
			}
		}
		else
		{
			if(n2>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					b[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]); 
					if(b[i]<0)
					{
						b[i]=b[i]/(-1);
					}
				}
				sort(b+1,b+1+n);
				for(int i=1;i<=n2-n/2;i++)
				{
					h=h-b[i];
				}
			}
			else
			{
				if(n3>n/2)
				{
					for(int i=1;i<=n;i++)
					{
						b[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
						if(b[i]<0)
						{
							b[i]=b[i]/(-1);
						}
					}
					sort(b+1,b+1+n);
					for(int i=1;i<=n3-n/2;i++)
					{
						h=h-b[i];
					}
				}
			}
		}
		cout<<h;
	}
	return 0; 
}


