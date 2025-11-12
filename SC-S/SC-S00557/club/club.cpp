#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int a[1008617][4];
vector<int> clubs[4];
int used[4];
bool cmp(int a,int b)
{
	return a<b;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
		int ans=0;
    	memset(used,0,sizeof(used));
    	clubs[1].clear();
    	clubs[2].clear();
    	clubs[3].clear();
    	memset(a,0,sizeof(a));
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    	    for(int j=1;j<=3;j++)
    	    {
    	    	cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				ans+=a[i][1];
				used[1]++;
				clubs[1].push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			}    
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				ans+=a[i][2];
				used[2]++;
				clubs[2].push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			}  
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
			{
				ans+=a[i][3];
				used[3]++;
				clubs[3].push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			}    
		}
		if(used[1]>n/2)
		{
			sort(clubs[1].begin(),clubs[1].end(),cmp);
			int begin=0;
			while(used[1]>n/2)
			{
				ans-=clubs[1][begin];
				begin++;
				used[1]--;
			}
		}
		else if(used[2]>n/2)
		{
			sort(clubs[2].begin(),clubs[2].end(),cmp);
			int begin=0;
			while(used[2]>n/2)
			{
				ans-=clubs[2][begin];
				begin++;
				used[2]--;
			}
		}
		else if(used[3]>n/2)
		{
			sort(clubs[3].begin(),clubs[3].end(),cmp);
			int begin=0;
			while(used[3]>n/2)
			{
				ans-=clubs[3][begin];
				begin++;
				used[3]--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}