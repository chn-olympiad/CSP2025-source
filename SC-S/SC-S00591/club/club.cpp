#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans=0;

struct m
{
	int ai;
	int id;
	int er;
	int san;
	short bumen;
}a[4];
vector<vector<m>>q;
bool cmp(m aa,m bb)
{
	return aa.ai>bb.ai;
}
bool cmp1(m aa,m bb)
{
	return aa.ai<bb.ai;
}
void clean()
{
	while(!q[1].empty())
	{
		q[1].pop_back();
	}
	while(!q[2].empty())
	{
		q[2].pop_back();
	}
	while(!q[3].empty())
	{
		q[3].pop_back();
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	
	q.resize(4);
	while(t--)
	{
		cin>>n;
		int mid=n/2;
		clean();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[j].ai;
				a[j].id=i;
				a[j].bumen=j;
			}
			
			sort(a+1,a+3+1,cmp);
			a[1].er=a[2].ai;
			a[1].san=a[3].ai;
			//cout<<a[1].ai<<a[2].ai<<a[3].ai<<"mmmm \n";
			q[a[1].bumen].push_back(a[1]);
			//cout<<q[a[1].bumen].front().bumen<<'\n';
		}
		sort(q[1].begin(),q[1].end(),cmp1);
		sort(q[2].begin(),q[2].end(),cmp1);
		sort(q[3].begin(),q[3].end(),cmp1);
		
		while(q[1].size()>mid)
		{
			if(q[1].front().er>=q[1].front().san)
			{
				q[1].front().ai= q[1].front().er;
				 q[2].push_back(q[1].front());
			}
			else{
				q[1].front().ai= q[1].front().san;
				q[3].push_back(q[1].front());
			}
			q[1].pop_back();
		}
		sort(q[2].begin(),q[2].end(),cmp1);
		sort(q[3].begin(),q[3].end(),cmp1);
		
		while(q[2].size()>mid)
		{
			q[2].front().ai= q[2].front().san;
			q[3].push_back(q[2].front());
			q[2].pop_back();
		}
		sort(q[3].begin(),q[3].end(),cmp1);	
		
		
		while(q[3].size()>mid)
		{
			if(q[2].size()<mid)
			{
				q[3].front().ai=q[3].front().er;
				q[2].push_back(q[3].front());
			}
			q[3].pop_back();
		}
		
		sort(q[2].begin(),q[2].end(),cmp1);			
		while(q[2].size()>mid)
		{
			q[2].pop_back();
		}

		
		ans=0;
		for(int i=1;i<=3;i++)
		{
			for(m j:q[i])
			{
				//cout<<"j="<<j.ai;
				ans+=j.ai;
			}
		}
		cout<<ans<<endl;
	}                                        
	return 0;
}