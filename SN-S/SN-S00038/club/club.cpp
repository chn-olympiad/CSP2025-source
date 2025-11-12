#include <bits/stdc++.h>
using namespace std;

long long t,n[100010],mij[100010][100010],x[100010][100010],ans[100010]; 
struct ma 
{
	int p,q,r;
}z[100010][100010];

int main()
{
	//freopen("club.in","w",stdin);
	//freopen("club.out","r",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		cin>>n[q];
		
		for(int i=1;i<=n[q];i++)
		{
			cin>>x[i][1]>>x[i][2]>>x[i][3];
		}
		
		for(int i=1;i<=n[q];i++)
		{
			if(i=1)
			{
				mij[1][1]=x[i][1];
				mij[1][2]=x[i][2];
				mij[1][3]=x[i][3];
				
				z[1][1].p=1;
				z[1][1].q=0;
				z[1][1].r=0;
				z[1][2].p=0;
				z[1][2].q=1;
				z[1][2].r=0;
				z[1][3].p=0;
				z[1][3].q=0;
				z[1][3].r=1;
				continue;
			}
			
			for(int j=1;j<=3;j++)
			{
				int f,g,h;
				f=mij[i-1][1];
				g=mij[i-1][2];
				h=mij[i-1][3];
				if((z[i-1][j].p+1)>(n[q]/2))f=0;
				if((z[i-1][j].q+1)>(n[q]/2))g=0;
				if((z[i-1][j].r+1)>(n[q]/2))h=0;
				mij[i][j]=max(f,g,h)+x[i][j];
			}
		}
		ans[q]=max(mij[n[q]][1],mij[n[q]][2],mij[n[q]][3]);
	}
	
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}


