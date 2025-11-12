#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,ans;
void Main(void);
struct node
{
	pair<int,int>d[5];
}a[100005];

signed main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		Main();
	}
}
bool cmp1(pair<int,int>x,pair<int,int>y)
{
	return x.first>y.first;
}

bool cmp(int x,int y)
{
	return a[x].d[1].first-a[x].d[2].first<a[y].d[1].first-a[y].d[2].first;
 } 
int club[5];
vector<int>cb[5];

void Main(void)
{
	ans=0;
	memset(a,0,sizeof(a));
	memset(club,0,sizeof(club));
	cb[1].clear();
	cb[2].clear();
	cb[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%lld",&a[i].d[j].first);
			a[i].d[j].second=j;
		}	
		sort(a[i].d+1,a[i].d+4,cmp1);	
	}
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].d[1].first;
		club[a[i].d[1].second]++;
		cb[a[i].d[1].second].push_back(i);
	}
	if(club[1]>n/2)
	{
		sort(cb[1].begin(),cb[1].end(),cmp);
		for(int i=0;i<club[1]-n/2;i++)
			ans-=a[cb[1][i]].d[1].first-a[cb[1][i]].d[2].first;
	}if(club[2]>n/2)
	{
		sort(cb[2].begin(),cb[2].end(),cmp);
		for(int i=0;i<club[2]-n/2;i++)
			ans-=a[cb[2][i]].d[1].first-a[cb[2][i]].d[2].first;
	}
	if(club[3]>n/2)
	{
		sort(cb[3].begin(),cb[3].end(),cmp);
		for(int i=0;i<club[3]-n/2;i++)
			ans-=a[cb[3][i]].d[1].first-a[cb[3][i]].d[2].first;
	}
	cout<<ans<<endl;
}
