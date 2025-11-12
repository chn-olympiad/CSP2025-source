#include<bits/stdc++.h>
using namespace std;
struct node
{
	int i;
	int data;
};

bool f1(node x,node y)
{
	return x.data>y.data;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
for(int T1=1;T1<=T;T1++){
	vector<node> v[4];
	int a[10007][3],maxa[10007];
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int maxx=0,m; 
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=maxx)
			{
				m=j;
				maxx=a[i][j];
			}
		}
		maxa[i]=m;
	}
	for(int i=1;i<=n;i++)
	{
		node t;
		t.i=i;
		t.data=a[i][maxa[i]];
		v[maxa[i]].push_back(t);
	}
	
	int maxl=max(v[1].size(),max(v[2].size(),v[3].size()));
	while(maxl>(n/2)+1)
	{
		maxl=max(v[1].size(),max(v[2].size(),v[3].size()));
		int club;
		for(int i=1;i<=3;i++)
		{
			if(v[i].size()==maxl)
			{
				club=i;
				break;
			}
		}
		sort(v[club].begin(),v[club].end(),f1);
		for(int i=(n/2);i<=maxl-1;i++)
		{
			a[v[club][i].i][maxa[v[club][i].i]]=-1;
			int maxx=0,m; 
			for(int j=1;j<=3;j++)
			{
				if(a[v[club][i].i][j]>=maxx)
				{
					m=j;
					maxx=a[v[club][i].i][j];
				}
			}
			maxa[i]=m;
			node t;
			t.i=v[club][i].i;
			t.data=a[v[club][i].i][maxa[v[club][i].i]];
			v[maxa[v[club][i].i]].push_back(t);
		}
		for(int i=(n/2);i<=maxl-1;i++)
		{
			v[club].pop_back();
		}
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			ans+=v[i][j].data;
		}
	}
	cout<<ans;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

