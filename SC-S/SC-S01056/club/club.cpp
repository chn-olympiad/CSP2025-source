#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int n,s;

struct m
{
	int ti;
	int ai;
	int yi;
	short bumen; 
}a[4];
vector < vector < m > > q;
bool num(m ab,m ac)
{
	return ab.ti>ac.ti;
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
	
	q.resize(4);
	
	while(s--)
	{
		cin>>n;
	    int mind=n/2;
	    
	    for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin>>a[j].ti;
				a[j].ai = i;
				a[j].bumen = j;
			}
			
			sort(a+1,a+n+1,num);
		} 
		sort(q[1].begin(),q[1].end(),num);
		sort(q[2].begin(),q[2].end(),num);
		sort(q[3].begin(),q[3].end(),num);
		while(q[1].size()>mind)
		{
			q[2].push_back(q[1].front());
			q[1].pop_back();
		}
		while(q[2].size()>mind)
		{
			q[3].push_back(q[2].front());
			q[2].pop_back();
		}
		while(q[3].size()>mind)
		{
			q[3].pop_back();
		}
		ans = 0;
		for(int i = 1;i <= 3;i++)
		{
			for(m j:q[i])
			{
				//cout<<j.ai<<endl;
				ans+=j.ai;
			}
		}
		cout<<ans<<endl;
	} 
	
	
	return 0;
}