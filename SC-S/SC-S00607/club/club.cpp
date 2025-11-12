#include<bits/stdc++.h>
using namespace std;
int t,ans=0;
int a[100100][5];		
int c[4],m[3][10001],n,y[200001];
void cmp(int i,int cp)
{
	if(cp==3)
	{
		ans+=a[i][a[i][4]];
		return;
	}
	int k=a[i][4];
	if(c[k]+1<=n/2)
	{
		ans+=a[i][k];
		c[k]++;
		m[k][c[k]]=a[i][k]; 
	}
	else
	{
		bool s=false,mni=1;
		for(int j=1;j<=c[k];j++)
		{
			if(m[k][j]<=a[i][k])
				s=true;
			if(m[k][j]<=m[k][mni])
				mni=j;
		}
		if(s)	
		{
			
			ans=ans-m[k][mni]+a[i][k];
			m[k][mni]=a[i][k];
			a[i][k]=m[k][mni];
			a[i][4]=(a[i][4]+1)%3;
			cmp(i,cp+1);
		}
		else
		{
			a[i][4]=(a[i][4]+1)%3;
			cmp(i,cp+1);				
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				a[i][4]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				a[i][4]=2;
			else
				a[i][4]=3;
		}
		int b=1; 
		for(int i=2;i<=n;i++)
		{
			if(a[i][4]!=a[i-1][4])
			{
				b=0;
				break;
			}
		}
		if(b==1)
		{
			int k=a[1][4];
			for(int i=1;i<=n;i++)
				y[i]=a[i][k];
			sort(y+1,y+n+1);
			for(int i=1;i<=n/2;i++)
				swap(y[i],y[n-i+1]);
			for(int i=1;i<=n/2;i++)
				ans+=y[i];
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=3;i++)
		{
			c[i]=0;
			for(int j=1;j<=n;j++)
				m[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cmp(i,0);
		}
		cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;	
} 