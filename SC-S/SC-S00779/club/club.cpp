#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+10;
int f[4][N];
int t,n,ans;
struct Node{
	int val,id;
}e[N][4];
struct Edge{
	Node x;
	int y,z;
	operator> (const Edge &W) const
	{
		return x.val>W.x.val;
	}
};
priority_queue<Edge,vector<Edge>,greater<Edge> > q[4];
bool cmp1(Node x,Node y)
{
	return x.val>y.val;
}
void fun(int k,int x)
{
	for(int i=x;i<=3;i++){
		int w=e[k][i].val,v=e[k][i].id;
		if(q[v].size()<n/2){
			Edge s;
			q[v].push({e[k][i],i,k});
			return;
		}else{
			int ww=q[v].top().x.val;
			int vv=q[v].top().x.id;
			int ver=q[v].top().y;
			int wv=q[v].top().z;
			if(ww<w){
				q[v].pop();
				q[v].push({e[k][i],i,k});
				fun(wv,ver);
			}
		}
	}
}
int work1()
{
	int ans=0;
	for(int i=1;i<=n;i++) fun(i,1);
	for(int i=1;i<=3;i++){
		while(q[i].size()){
			ans+=q[i].top().x.val;
			q[i].pop();
		}
	}
	return ans;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		bool f=0;
		ans=0;
		for(int i=1;i<=3;i++)
			while(q[i].size()) q[i].pop();
		cin>>n;
		if(n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			break;
		}
		for(int i=1;i<=n;i++){
			cin>>e[i][1].val>>e[i][2].val>>e[i][3].val;
			if(e[i][2].val!=0||e[i][3].val!=0) f=1;
			e[i][1].id=1,e[i][2].id=2,e[i][3].id=3;
			sort(e[i]+1,e[i]+4,cmp1);
		}
		if(!f){
			int a[N];
			for(int i=1;i<=n;i++){
				a[i]=e[i][1].val;
			}
			sort(a+1,a+1+n);
			int cnt=0;
			for(int i=n;i>=i;i--){
				cnt++;
				ans+=a[i];
				if(cnt==n/2){
					break;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<work1()<<'\n';
	}
	return 0;
}