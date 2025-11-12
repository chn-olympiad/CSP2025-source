#include<bits/stdc++.h>
using namespace std;
long long int t,n,i,j,a[10005][5],b[10005][5],maxn,ans,c[5],f1[10005][5],f2[10005][5],f3[10005][5],y;
int main( )
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f1));
		memset(f3,0,sizeof(f1));
		memset(c,0,sizeof(c));
		ans=0;
		maxn=INT_MIN;
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		 while((c[1]<=n/2)&&(c[2]<=n/2)&&(c[3]<=n/2)&&(c[1]+c[2]+c[3]<=n))
		 {
		 	for(i=1;i<=n&&f1[i][1]==0&&f1[i][2]==0&&f1[i][3]==0;i++)
		 	if(a[i][1]>maxn)
			 {
		 		maxn=a[i][1];
		 		y=i;
		 	}
		 	f1[y][1]=1;f1[y][2]=1;f1[y][3]=1;
		 	ans+=maxn;
		 	if(maxn>0)
		 	c[1]++;
		 	maxn=0;
		 	if(c[1]+c[2]+c[3]>=n)
		 	break;
		 	
		 	for(i=1;i<=n&&f2[i][1]==0&&f2[i][2]==0&&f2[i][3]==0;i++)
		 	if(a[i][2]>maxn)
			 {
		 		maxn=a[i][2];
		 		y=i;
		 	}
		 	f2[y][1]=1;f2[y][2]=1;f2[y][3]=1;
		 	ans+=maxn;
		 	c[2]++;
		 	maxn=0;
		 	if(c[1]+c[2]+c[3]>=n)
		 	break;
		 	
		 	for(i=1;i<=n&&f3[i][1]==0&&f3[i][2]==0&&f3[i][3]==0;i++)
		 	if(a[i][3]>maxn)
		 	{
		 		maxn=a[i][3];
		 		y=i;
		 	}
		 	f3[y][1]=1;f3[y][2]=1;f3[y][3]=1;
		 	ans+=maxn;
		 	if(maxn>0)
		 	c[3]++;
		 	maxn=0;
		 	if(c[1]+c[2]+c[3]>=n)
		 	break;
		}
		cout<<ans;
		cout<<endl; 
	}

	return 0;
 } 

