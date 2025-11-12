#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100019;
int n,m,ans,T,x,y,z,q1,q2;
vector<int>b[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		for(int i=1;i<=3;i++)b[i].clear();
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
		scanf("%d%d%d",&x,&y,&z);
		if(x>=y&&x>=z) q1=1,ans+=x,q2=min(x-y,x-z);
		else if(y>=x&&y>=z) q1=2,ans+=y,q2=min(y-x,y-z);
		else q1=3,ans+=z,q2=min(z-x,z-y);
		b[q1].push_back(q2);
		}
		for(int i=1;i<=3;i++)
			if(b[i].size()>n/2)
			{
				sort(b[i].begin(),b[i].end());
				for(int k=0;k<b[i].size()-n/2;k++) ans-=b[i][k];
				break; 
			}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
