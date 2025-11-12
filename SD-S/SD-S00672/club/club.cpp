#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio> 
using namespace std;
const int N=1e5+5;
int a[N][5],n,t,cnt=0,lmt[5],vis[N];
long long ans=0;
struct Node
{
	int w;
	int id1;
	int id2;
}b[3*N];
bool cmp(Node x,Node y)
{
	return x.w>y.w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt=0;
		ans=0;
		lmt[1]=0;
		lmt[2]=0;
		lmt[3]=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
	 	}
	 	for(int i=1;i<=n;i++)
	 	{
	 		cnt++;
			b[cnt].w=a[i][1]-max(a[i][2],a[i][3]);
			b[cnt].id1=1;
			b[cnt].id2=i;
			cnt++;
			b[cnt].w=a[i][2]-max(a[i][1],a[i][3]);
			b[cnt].id1=2;
			b[cnt].id2=i;
			cnt++;
			b[cnt].w=a[i][3]-max(a[i][2],a[i][1]);
			b[cnt].id1=3;
			b[cnt].id2=i;
		}
		sort(b+1,b+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
//			cerr<<b[i].w<<" "<<b[i].id<<"\n"; 
			if(lmt[b[i].id1]>=n/2||vis[b[i].id2]==1)continue;
//			cerr<<b[i].w<<" "<<b[i].id1<<" "<<b[i].id2<<"\n";
			ans+=a[b[i].id2][b[i].id1];
			lmt[b[i].id1]++;
			vis[b[i].id2]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
