#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5],b[1000000],f[N][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,i,j,k,t,ans=0,x,y,X,Y;
	memset(f,0,sizeof(f));
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int flag=1,s=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 || a[i][3]!=0)
			{
				flag=0;
			} 
			b[++s]=a[i][1];
		}
		if(flag==1)
		{
			sort(b+1,b+s+1);
			for(i=s;i>=s-(n/2)+1;i--) ans+=b[i];
			cout<<ans<<endl;
		}
		else if(n==2)
		{
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[1][i]+a[2][j]); 
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(n==4)
		{
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					for(x=1;x<=3;x++)
					{
						for(y=1;y<=3;y++)
						{
							int fl=1,cnt=0;
							f[1][i]=1;
							f[2][j]=1;f[3][x]=1;f[4][y]=1;
							for(X=1;X<=3;X++)
							{
								for(Y=1;Y<=n;Y++)
								{
									if(f[Y][X]!=0) cnt++;
									if(cnt>2)
									{
										fl=0;
										break;
									}
									cnt=0;
								}
								
							}
							if(fl==1)
							{
								ans=max(ans,a[1][i]+a[2][j]+a[3][x]+a[4][y]);
							}
						}
					}
				}
			}memset(f,0,sizeof(f));
			cout<<ans<<endl;
			
		}
	}
	return 0;
} 
