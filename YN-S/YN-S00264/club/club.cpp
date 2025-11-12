#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5;
int over=0;
struct member
{
	int b1,b2,b3;
	int delta;
}m[N];
vector<member>d[4];
bool operator<(member a,member b)
{
	return a.delta<b.delta;
}
int maxinum(member a)
{
	int x=a.b1,y=a.b2,z=a.b3;
	if(x>=y)
	{
		if(x>=z)return 1;
		else return 3;
	}
	else
	{
		if(y>=z)return 2;
		else return 3;
	}
}
void reset()
{
	for(int i=0;i<N;i++)m[i]={0,0,0,0};
	over=0;
	for(int i=0;i<=3;i++)d[i].clear();
}
int output()
{
	int s[4];
	int ans=0;
	for(int i=1;i<=3;i++)s[i]=d[i].size();
	for(int j=0;j<s[1];j++)ans+=d[1][j].b1;
	for(int j=0;j<s[2];j++)ans+=d[2][j].b2;
	for(int j=0;j<s[3];j++)ans+=d[3][j].b3;
	return ans;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	cin.get();
	while(t--)
	{
		scanf("%d",&n);
		cin.get();
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&m[i].b1,&m[i].b2,&m[i].b3);
			cin.get();
			d[maxinum(m[i])].push_back(m[i]);
		}
		for(int i=1;i<=3;i++)		
			if(d[i].size()>n>>1)over=i;
		
		int ans=output();
		if(!over)
		{
			printf("%d\n",ans);
			reset();
			continue;
		}
		for(int i=0;i<d[over].size();i++)
		{
			int res;
			int x=d[over][i].b1;
			int y=d[over][i].b2;
			int z=d[over][i].b3;
			switch (over) {
			case 1:
				res=x-max(y,z);
				break;
			case 2:
				res=y-max(x,z);
				break;
			default:
				res=z-max(y,z);
				break;
			}
			d[over][i].delta=res;
		}
		sort(d[over].begin(),d[over].end());
		int sizee=d[over].size()-(n>>1);
		for(int i=0;i<sizee;i++)
			ans-=d[over][i].delta;
		printf("%d\n",ans);
		
		reset();
	}
	return 0;
}
