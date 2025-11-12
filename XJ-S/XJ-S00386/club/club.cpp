#include<cstdio>
int t,n,a[50005][3],b[50005][3],m[50005][3];
int ans;
int min(int x,int y,int z)
{
	if(x<y&&x>z||x<z&&x>y) return x;
	else if(x<y&&y<z||y<x&&y>z) return y;
	return z;	
}
int max(int x,int y,int z)
{
	if(x>y&&x>z) return x;
	else if(y>z) return y;
	else return z;	
}
int max2(int x,int y)
{
	if(x>y) return x;
	return y;	
}
int main()
{
	int x,i,j,c;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			c=min(a[i][1],a[i][2],a[i][3]);
			b[i][1]=a[i][1]-c;
			b[i][2]=a[i][2]-c;
			b[i][3]=a[i][3]-c;
			c=max(b[i][1],b[i][2],b[i][3]);
			m[i][1]=c;
			if(c==b[i][1]) m[i][2]=1;
			else if(c==b[i][2]) m[i][2]=2;
			else m[i][2]=3;
			m[i][3]=i;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n-1;j++)
			{
				if(m[j][1]<m[j+1][1])
				{
					c=m[j][1];m[j][1]=m[j+1][1];m[j+1][1]=c;
					c=m[j][2];m[j][2]=m[j+1][2];m[j+1][2]=c;
					c=m[j][3];m[j][3]=m[j+1][3];m[j+1][3]=c;
				}
			}
		}
		int s[5]={0,0,0,0};
		for(i=1;i<=n;i++)
		{
			if(s[m[i][2]]+1<=n/2)
			{
				ans=ans+a[m[i][3]][m[i][2]];
				s[m[i][2]]++;
			}
			else 
			{
				if(m[i][2]==1)
				{
					c=max2(a[m[i][3]][2],a[m[i][3]][3]);
					ans=ans+c;
					if(c==a[m[i][3]][2])
					{
						s[2]++;
					} 
					else 
					{
						s[3]++;
					}
				}
				else if(m[i][2]==2)
				{
					c=max2(a[m[i][3]][1],a[m[i][3]][3]);
					ans=ans+c;
					if(c==a[m[i][3]][1]) 
					{
						s[1]++;
					} 
					else 
					{
						s[3]++;
					}
				}
				else
				{
					c=max2(a[m[i][3]][1],a[m[i][3]][2]);
					ans=ans+c;
					if(c==a[m[i][3]][1])
					{
						s[1]++;
					} 
					else 
					{
						s[2]++;
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;	
} 
