#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T, n, a[maxn][5], t[maxn], b[maxn], tot;
vector<int> vec[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int sum=0;
		vec[1].clear(), vec[2].clear(), vec[3].clear();
		for(int i=0;i<=n;i++) b[i]=t[i]=0;
		for(int i=1;i<=n;i++)
		{
			int mx=0, se=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=a[i][mx]) se=mx, mx=j;
				else if(a[i][j]>=a[i][se]) se=j;
			}
			sum+=a[i][mx];
			b[i]=a[i][mx]-a[i][se];
			vec[mx].push_back(i);
		}
		for(int i=1;i<=3;i++)
		{
			int cnt=vec[i].size();
			if(cnt>n/2)
			{
				tot=0;
				for(int j=0;j<cnt;j++)
				{
					t[++tot]=b[vec[i][j]];
				}
				sort(t+1, t+tot+1);
				for(int j=1;j<=cnt-n/2;j++)
				{
					sum-=t[j];
				}
				break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
