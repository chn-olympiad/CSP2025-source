#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int n;
int q;
map<int,vector<int>> minn;
int main()
{
	fre();
	cin>>n>>q;
	for(int i = 1; i<=n; i++)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
		pair<int,int> t;
		for(int j = 0; j<s1.size(); j++)
		{
			if(s1[j] == 'b')
			{
				t.first = j;
				break;
			}
		}
		for(int j = 0; j<s2.size(); j++)
		{
			if(s2[j] == 'b')
			{
				t.second = j;
				break;
			}
		}
		minn[t.second-t.first].push_back(s1.size());
	}
	for(int i = 1; i<=q; i++)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
		pair<int,int> q;
		for(int j = 0; j<s1.size(); j++)
		{
			if(s1[j] == 'b')
			{
				q.first = j;
				break;
			}
		}
		for(int j = 0; j<s2.size(); j++)
		{
			if(s2[j] == 'b')
			{
				q.second = j;
				break;
			}
		}
		int ans = 0;
		if(minn.count(q.second-q.first))
		{
			for(int i : minn[q.second-q.first])
			{
				if(i<=s1.size())
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}