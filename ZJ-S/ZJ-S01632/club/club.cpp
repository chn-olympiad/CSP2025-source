#include<bits/stdc++.h>
using namespace std;
int clu[4];
struct xuesheng{
	int man1,man2,man3;
	int bian1,bian2,bian3;
	int cha1,cha2;
}x[100010];
bool cmp(xuesheng a,xuesheng b)
{
	if(a.cha1!=b.cha1)
	{
		return a.cha1<b.cha1;
	}
	return a.cha2<b.cha2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		memset(clu,0,sizeof(clu));
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[i].man1,&x[i].man2,&x[i].man3);
			x[i].bian1=1;x[i].bian2=2;x[i].bian3=3;
			if(x[i].man1<x[i].man3)
			{
				swap(x[i].man1,x[i].man3);
				swap(x[i].bian1,x[i].bian3);
			}
			if(x[i].man2<x[i].man3)
			{
				swap(x[i].man2,x[i].man3);
				swap(x[i].bian2,x[i].bian3);
			}
			if(x[i].man1<x[i].man2)
			{
				swap(x[i].man1,x[i].man2);
				swap(x[i].bian1,x[i].bian2);
			}
			x[i].cha1=x[i].man1-x[i].man2;
			x[i].cha2=x[i].man2-x[i].man3;
			clu[x[i].bian1]++;
			ans+=x[i].man1;
		}
		sort(x+1,x+n+1,cmp);
		if(clu[1]>(n/2))
		{
			while(clu[1]>(n/2))
			{
				for(int i=1;i<=n;i++)
				{
					if(x[i].bian1==1)
					{
						ans-=x[i].cha1;
						clu[x[i].bian2]++;
						clu[1]--;
						if(clu[x[i].bian2]>(n/2))
						{
							ans-=x[i].cha2;
							clu[x[i].bian2]--;
							clu[x[i].bian3]++;
						}
					}
					if(clu[1]<=(n/2))
					{
						break;
					}
				}
			}
		}
		if(clu[2]>(n/2))
		{
			while(clu[2]>(n/2))
			{
				for(int i=1;i<=n;i++)
				{
					if(x[i].bian1==2)
					{
						ans-=x[i].cha1;
						clu[x[i].bian2]++;
						clu[2]--;
						if(clu[x[i].bian2]>(n/2))
						{
							ans-=x[i].cha2;
							clu[x[i].bian2]--;
							clu[x[i].bian3]++;
						}
					}
					if(clu[2]<=(n/2))
					{
						break;
					}
				}
			}	
		}
		if(clu[3]>(n/2))
		{
			while(clu[3]>(n/2))
			{
				for(int i=1;i<=n;i++)
				{
					if(x[i].bian1==1)
					{
						ans-=x[i].cha1;
						clu[x[i].bian2]++;
						clu[3]--;
						if(clu[x[i].bian2]>(n/2))
						{
							ans-=x[i].cha2;
							clu[x[i].bian2]--;
							clu[x[i].bian3]++;
						}
					}
					if(clu[3]<=(n/2))
					{
						break;
					}
				}
			}
	
		}
		cout<<ans<<endl;
	}
	return 0;
}
