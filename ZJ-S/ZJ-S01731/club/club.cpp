#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int a[maxn][4],c[4];
int t[4];
vector<int>b[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int tl;
	cin>>tl;
	while(tl--)
	{
		for(int i=1;i<=3;i++)
			b[i].clear();
		t[1]=0,t[2]=0,t[3]=0;
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			c[1]=a[i][1],c[2]=a[i][2],c[3]=a[i][3];
			sort(c+1,c+1+3);
			for(int j=1;j<=3;j++)
				if(c[3]==a[i][j])
				{
					t[j]++;
					b[j].push_back(c[3]-c[2]);
					ans+=c[3];
					break;
				}
		}
		if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		for(int j=1;j<=3;j++)
			if(t[j]>n/2)
			{
				sort(b[j].begin(),b[j].end());
				int i=0;
				while(t[j]>n/2)
				{
					ans-=b[j][i];
					t[j]--;
					i++;
					
				}
				break;
			}
		cout<<ans<<endl;
	}
	return 0;
}


