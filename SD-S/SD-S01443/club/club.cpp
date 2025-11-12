#include<cstdio>
#include<iostream> 
#include<algorithm>
using namespace std;
int t,n,x,y,z;
long long sumt;
int a1[100005],b[100005],a2[100005],a3[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			
		}
		for(int i=1;i<=n;++i)
		{
			if(a1[i]==a2[i]&&a2[i]==a3[i])sumt+=a2[i];
			if(a1[i]==a2[i]&&a1[i]>a3[i])sumt+=a1[i];
			if(a2[i]==a3[i]&&a2[i]>a1[i])sumt+=a2[i];
			if(a1[i]==a3[i]&&a1[i]>a2[i])sumt+=a3[i];
			if(a1[i]>a2[i]&&a1[i]>a3[i]){sumt+=a1[i];x++;}
			if(a2[i]>a1[i]&&a2[i]>a3[i]){sumt+=a2[i];y++;}
			if(a3[i]>a2[i]&&a3[i]>a1[i]){sumt+=a3[i];z++;}
		}
		if(x>n/2)
		{
			for(int i=1;i<=n;++i)
			{
				b[i]=a1[i]-max(a2[i],a3[i]);
			}
			sort(b+1,b+n+1);
			int rd=x-(n/2);
			for(int i=1;i<=n;++i)
			{
				if(rd==0)break;
				if(b[i]>0)
				{
					sumt-=b[i];
					rd--;
				}
			}
		}
		if(y>n/2)
		{
			for(int i=1;i<=n;++i)
			{
				b[i]=a2[i]-max(a1[i],a3[i]);
			}
			sort(b+1,b+n+1);
			int rd=y-(n/2);
			for(int i=1;i<=n;++i)
			{
				if(rd==0)break;
				if(b[i]>0)
				{
					sumt-=b[i];
					rd--;
				}
			}
		}
		if(z>n/2)
		{
			for(int i=1;i<=n;++i)
			{
				b[i]=a3[i]-max(a2[i],a1[i]);
			}
			sort(b+1,b+n+1);
			int rd=z-(n/2);
			for(int i=1;i<=n;++i)
			{
				if(rd==0)break;
				if(b[i]>0)
				{
					sumt-=b[i];
					rd--;
				}
			}
		}
		cout<<sumt<<endl;
		 for(int i=1;i<=n;++i)a1[i]=a2[i]=a3[i]=b[i]=0;
		 n=0;x=0;y=0;z=0;sumt=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
