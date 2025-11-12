#include<bits/stdc++.h>
using namespace std;
int T,n,x,y,z1;
int z[4];
int w[100005][4],s[100005][4];
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>T;
	//cout<<a[1].w[1]<<" "<<a[1].s[1];
	while(T--)
	{
		int ans=0;
		cin>>n;
		z[1]=z[2]=z[3]=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z1;
	 		if(x>y>z1)
			{
				w[i][1]=x;
				w[i][2]=y;
				w[i][3]=z1;
				s[i][1]=1;
				s[i][2]=2;
				s[i][3]=3;
			}
			else if(x>z1>y)
			{
				w[i][1]=x;
				w[i][2]=z1;
				w[i][3]=y;
				s[i][1]=1;
				s[i][2]=3;
				s[i][3]=2;
			}
			else if(y>x>z1)
			{
				w[i][1]=y;
				w[i][2]=x;
				w[i][3]=z1;
				s[i][1]=2;
				s[i][2]=1;
				s[i][3]=3;
			}
			else if(y>z1>x)
			{
				w[i][1]=y;
				w[i][2]=z1;
				w[i][3]=x;
				s[i][1]=2;
				s[i][2]=3;
				s[i][3]=1;
			}
			else if(z1>x>y)
			{
				w[i][1]=z1;
				w[i][2]=x;
				w[i][3]=y;
				s[i][1]=3;
				s[i][2]=1;
				s[i][3]=2;
			}
			else
			{
				w[i][1]=z1;
				w[i][2]=y;
				w[i][3]=x;
				s[i][1]=3;
				s[i][2]=2;
				s[i][3]=1;
			}
		}
		if(w[1][2]==0&&w[1][3]==0)
		{
			int maxx=0,idd;
			for(int i=1;i<=n/2;i++)
			{
				//cout<<"a";
				for(int j=1;j<=n;j++)
				{
					if(maxx<=w[j][1])
					{
						idd=j;
						maxx=w[j][1];
					}
				}
				ans+=maxx;
				w[idd][1]=-1;
				maxx=0;
			}
			cout<<ans<<endl;
			break;
		}
		for(int i=1;i<n;i+=2)
		{
			int id1,id2;
			int maxn=0;
			int num1;
			int num2;
			for(int j=1;j<=3;j++)
			{
				if(z[s[i][j]]>=1)
				{
					num1=j;
					break;
				}
			}
			for(int j=1;j<=3;j++)
			{
				if(z[s[i+1][j]]>=1)
				{
					num2=j;
					break;
				}
			}
			//cout<<num1<<" "<<num2<<endl;
			int w1,w2;
			for(int j=num1;j<=3;j++)
			{
				for(int k=num2;k<=3;k++)
				{
					if(j==k) continue;
					if(z[s[i][j]]>0&&z[s[i+1][k]]>0)
					{
						if(maxn<w[i][j]+w[i+1][k])
						{
							id1=z[s[i][j]];
							id2=z[s[i+1][k]];
							maxn=w[i][j]+w[i+1][k];
							w1=w[i][j];
							w2=w[i+1][k];
							//i++;
						}
					}
				}
			}
			//cout<<w1<<" "<<w2<<endl;
			z[id1]--;
			z[id2]--;
			ans+=maxn;	
		}
		cout<<ans<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
