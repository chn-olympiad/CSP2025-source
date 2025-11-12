#include<bits/stdc++.h>
using namespace std;
int s1[10],s2[100000][5],s3[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a=0,b,n,t,s=0;
	cin>>t;
	for(int r=1;r<=t;r++)
	{
		n=0;
		cin>>n;
		s=0;
		memset(s2,0,sizeof(s2));
		memset(s1,0,sizeof(s1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>s2[i][j];
			}
		}
		for(int i=3;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
			{
				for(int r=1;r<=n;r++)
				{
					if(s2[r][i]<s2[r+1][i])
						swap(s2[r],s2[r+1]);
				}
			}	
		}
		for(int i=1;i<=n;i++)
		{
			if(s2[i][1]>=s2[i][2]&&s2[i][1]>=s2[i][3]&&s1[1]<n/2)	
			{
				s+=s2[i][1];
				s1[1]+=1;
			}
		
			else if(s2[i][2]>=s2[i][1]&&s2[i][2]>=s2[i][3]&&s1[2]<n/2)	
			{
				s+=s2[i][2]; 
				s1[2]+=1;
			}
			else if(s2[i][3]>=s2[i][2]&&s2[i][3]>=s2[i][1]&&s1[3]<n/2)	
			{
				s+=s2[i][3];
				s1[3]+=1;
			}	
		}
		s3[a]=s;
		a++;
	}
	for(int i=0;i<a-1;i++)
		cout<<s3[i]<<endl;
	cout<<s3[a-1];
	return 0;
 } 