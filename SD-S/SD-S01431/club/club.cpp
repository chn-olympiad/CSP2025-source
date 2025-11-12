#include <bits/stdc++.h>
using namespace std;
int t,ans,n,a[100005][5],locat[100005],wher[4];
//locat:每个人的位置；    wher:每个位置多少人.
int jl[100005],bf[100005],bhdl,minn=1000000000; 
//记录，备份. 
void duo(int z)
{
	for(int i=1;i<=n;i++)
	{
		if(locat[i]==z) 
		{
			bf[i]=locat[i];
			a[i][z]=0;
			a[i][4]=max(a[i][1],max(a[i][2],a[i][3]));
			jl[i]=a[i][bf[i]]-a[i][4];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((jl[i]<minn) && (locat[i]==z))
		{
			minn=jl[i];
			bhdl=i;
		}
	}
	ans-=minn;
	wher[z]--;
	for(int i=1;i<=n;i++)
	{
		if(locat[i]==z)
		{
			if(i==bhdl)
			{
				for(int j=1;j<=3;j++)
				{
					if(a[i][j]==a[i][4])
					{
						locat[i]=j;
						wher[j]++;
					}
				}
			}
			else a[i][z]=a[i][4]=a[i][bf[i]];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int T=1; T<=t; T++)
	{
		ans=0;
		wher[0]=0;
		wher[1]=0;
		wher[2]=0;
		wher[3]=0;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)cin>>a[i][j];
			if(a[i][1]>a[i][2])locat[i]=1;
			else locat[i]=2;
			if(a[i][3]>a[i][locat[i]])locat[i]=3;
			a[i][4]=a[i][locat[i]];
			if(locat[i]==1)wher[1]++;
			else if(locat[i]==2)wher[2]++;
			else wher[3]++;
			ans+=a[i][4];
		}
		while (true)
		{ 
			if(wher[1]<=n/2)
			{
				if(wher[2]<=n/2)
				{
					if(wher[3]<=n/2)
					{
						cout<<ans<<endl;
						break;
					}
					else duo(3);
				}
				else duo(2);
			}
			else duo(1);
		}
	}
	return 0;
}
