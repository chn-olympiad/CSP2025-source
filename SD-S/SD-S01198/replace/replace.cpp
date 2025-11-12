#include<bits/stdc++.h>
#define int long long
#define c(x) cout<<"#x"<<" = "<<x<<endl;
using namespace std;
const int N=2010;
struct node{
	string s1,s2;
}e[N];
int n,m,idx;
map<string,int> mp;
map<int,string> qwq;
vector<int> q[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].s1>>e[i].s2;
		if(!mp[e[i].s1])
		{
			mp[e[i].s1]=++idx;
			qwq[idx]=e[i].s1;
		} 
		if(!mp[e[i].s2])
		{
			mp[e[i].s2]=++idx;
			qwq[idx]=e[i].s2;
		} 
		q[mp[e[i].s1]].push_back(mp[e[i].s2]);
	}
	if(n<=100)
	{
		while(m--)
		{
			string t1,t2;
			cin>>t1>>t2;
			int ans=0;
			for(int l=0;l<t1.size();l++)
			{
				for(int r=l;r<t1.size();r++)
				{
					string ss=t1.substr(l,r-l+1);
					if(mp[ss])
					{
						string ttt=t1;
						for(auto to:q[mp[ss]])
						{
							string tt=qwq[to];
							for(int i=0;i<tt.size();i++)
							{
								ttt[i+l]=tt[i];
							}
							if(ttt==t2)
							{
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	
	}
	return 0;
}


