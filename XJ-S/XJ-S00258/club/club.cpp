#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n;

struct value
{
	int v,cl,con;
	bool operator<(const value k)const
	{
		return v>k.v;
	}
}
a[N][4];

int f[4];
struct node
{
	long long con,val,id,r;
	
	bool operator<(const node k)const
	{
		return con>k.con;
	}
};
priority_queue<node> q[4];

int main()
{
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=3;i++)
			while(!q[i].empty())
				q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			a[i][1].cl=1,a[i][2].cl=2,a[i][3].cl=3;
		}
		for(int i=1;i<=n;i++)
			sort(a[i]+1,a[i]+4);
		for(int i=1;i<=n;i++)
			a[i][1].con=a[i][1].v-a[i][2].v,a[i][2].con=a[i][2].v-a[i][3].v,a[i][3].con=a[i][3].v;
		for(int i=1;i<=n;i++)
		{
			int pre=a[i][1].cl;
			q[pre].push((node){a[i][1].con,a[i][1].v,i,1});
			while(q[pre].size()>n/2)
			{
				node now=q[pre].top();
				q[pre].pop();
				int content=now.con,satis=now.val,fir=now.id,sec=now.r;
				value ref=a[fir][sec+1];
				int chav=ref.v,chacl=ref.cl,chacon=ref.con;
				q[chacl].push((node){chacon,chav,fir,sec+1});
			}
		}
		long long ans=0;
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())
			{
				ans+=q[i].top().val;
				q[i].pop();
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
} 
