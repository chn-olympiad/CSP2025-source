#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> mp;
int n,q;
int st,en,ln;

void dif(string a,string b)
{
	bool flag=0;
	for(int i=0;i<int(a.size());i++)
	{
		if(a[i]!=b[i])
		{
			if(!flag)
			{
				st=i;
				flag=1;
			}
			else
				en=i;
		}
	}
	ln=en-st+1;
	return ;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--)
	{
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		dif(s1,s2);
		for(int i=ln;i<=int(s1.size());i++)
		{
			int p=i-ln,lm=max(0,st-p);
			for(int j=st;j>=lm;j--)
			{
				if(mp[s1.substr(j,i)]==s2.substr(j,i))
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	cout<<endl;
	return 0;
}

