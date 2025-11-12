#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int t,n,club[N],clubb[N],clubbb[N],ans,anss,sum;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		ans=0;
		anss=0;
		for(int j=1;j<=n;j++)
		{
			cin>>club[j]>>clubb[j]>>clubbb[j];
			ans+=clubb[j];
			anss+=clubbb[j]; 
		}
		if(n==2)
		{
			int maxx=0;
			for(int j=1;j<=3;j++)
			{
				for(int jj=1;jj<=3;jj++)
				{
					if(j==1 and jj==2)
					{
						maxx=max(maxx,club[1]+clubb[2]);
					}
					if(j==1 and jj==3)
					{
						maxx=max(maxx,club[1]+clubbb[2]);
					}
					if(j==2 and jj==1)
					{
						maxx=max(maxx,clubb[1]+club[2]);
					}
					if(j==2 and jj==3)
					{
						maxx=max(maxx,clubb[1]+clubbb[2]);
					}
					if(j==3 and jj==1)
					{
						maxx=max(maxx,clubbb[1]+club[2]);
					}
					if(j==3 and jj==2)
					{
						maxx=max(maxx,clubbb[1]+clubb[2]);
					}
				}
			}
			cout<<maxx<<endl;
			continue;
		}
		if(ans==0 and anss==0)
		{
			sort(club+1,club+n+1,cmp);
		    int ans=0;
		    for(int j=1;j<=n/2;j++)
		    {
			    ans+=club[j];
		    }
		    cout<<ans<<endl;
		    continue;
		}
		for(int j=1;j<=n;j++)
		{
			int maxx=0;
			maxx=max(maxx,club[j]);
			maxx=max(maxx,clubb[j]);
			maxx=max(maxx,clubbb[j]);
			sum+=maxx;
		}
		cout<<sum<<endl;
	}
	return 0;
}
