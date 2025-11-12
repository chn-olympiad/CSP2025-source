#include<bits/stdc++.h>
using namespace std;
int n,q,anss;
struct node
{
	string s1,s2;
	
}a[200005];
struct node2
{
	string ss;
	bool f=0;
};
string qq,ans;
void bfs()
{
	queue<node2>qu;
	qu.push({qq});
	while(!qu.empty())
	{
		node2 now=qu.front();
		qu.pop();
		if(now.ss==ans)
		{
			anss++;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(now.f)continue;
			for(int j=0;j+a[i].s1.size()-1<now.ss.size();j++)
			{
				if(now.ss.substr(j,a[i].s1.size())==a[i].s1)
				{
					string s22=now.ss.substr(0,j)+a[i].s2+now.ss.substr(j+a[i].s1.size());
					qu.push({s22,1});
				}
			}
			
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--)
	{
		anss=0;
		cin>>qq>>ans;
		bfs();
		cout<<anss<<endl;
	}
	return 0;
}
