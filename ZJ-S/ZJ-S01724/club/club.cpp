#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[4][N],a1[4][N],a2[4][N];
int add[N],l1=1,l2=1;
struct cmp{
	bool operator ()(const int x,const int y)
	{
		return a[add[x]][x]>a[add[y]][y];
	}
};
struct cmp2{
	bool operator ()(const int &x,const int y)
	{
		
		return a2[add[x]][x]<a2[add[y]][y];
	}
};
priority_queue<int,vector<int>,cmp>q[4];
priority_queue<int,vector<int>,cmp2>q2[4];
int n;
void fi(int i)
{
//	cout<<i<<":";
	int j=1;
	//cout<<a1[j][i]<<'\n';
	if(q[a1[1][i]].size()<(n/2))
	{
		q[a1[1][i]].push(i);
		q2[a1[1][i]].push(i);
		add[i]=1;
		return;
	}
	else
	{
		int kt=1;
		int qq2=q2[a1[1][i]].top();
	//	cout<<qq2<<'\n';
	//	cout<<"kt"<<":"<<kt<<"	"<<a2[kt][qq2]<<"	"<<a1[j][i]<<"	"<<a2[j][i]<<'\n';
		if(a2[1][qq2]<a2[1][i])
		{
		//	cout<<"qq2:"<<qq2<<'\n';
			int temp=q2[a1[1][i]].top();
			q[a1[1][i]].pop();
			q2[a1[1][i]].pop();
			q2[a1[1][i]].push(i);
			q[a1[1][i]].push(i);
			add[i]=1;
			q[a1[2][temp]].push(temp);
			q2[a1[2][temp]].push(temp);
			add[temp]=2;
			return ;
		}
		else
		{
			q[a1[2][i]].push(i);
			q2[a1[2][i]].push(i);
			add[i]=2;
		}
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		fill(a[0],a[0]+4*N,0);
		fill(a1[0],a1[0]+4*N,0);
		fill(add,add+N,0);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0) l1=0;
			if(a[3][i]!=0)
			{
				l1=l2=0;
			}
		}
		if(l1==1)
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				q[1].push(i);
			}
			while(!q[1].empty())
			{
				ans+=a[1][q[1].top()];
				q[1].pop();
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) a1[j][i]=j;
			for(int j=1;j<=2;j++)
			{
				if(a[a1[j][i]][i]<a[a1[j+1][i]][i])
				{
					swap(a1[j][i],a1[j+1][i]);
				}
			}
			if(a[a1[1][i]][i]<a[a1[2][i]][i]) swap(a1[1][i],a1[2][i]);
		//	for(int j=1;j<=3;j++) cout<<a1[j][i]<<" ";
		//	cout<<'\n';
			for(int j=1;j<=2;j++)
			{
				a2[j][i]=a[a1[j][i]][i]-a[a1[j+1][i]][i];
			//	cout<<a2[j][i]<<" ";
			}
			a2[3][i]=a[a1[3][i]][i];
		//	cout<<a2[3][i]<<'\n';
			fi(i);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=1ll*(ans+a[a1[add[i]][i]][i]);
		}
		cout<<ans<<'\n';
		for(int i=1;i<=3;i++)
		{
			while(!q2[i].empty()) q2[i].pop();
			while(!q[i].empty()) q[i].pop();
		}
	}
	return 0;
}
