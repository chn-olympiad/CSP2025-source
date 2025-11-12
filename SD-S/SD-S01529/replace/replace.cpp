#include<bits/stdc++.h>
const int L=1e4+5,N=1e3+5;

using namespace std;

int nxt[L][N];
void getnxt(string s,int n,int id)
{
	nxt[0][id]=0;
	for(int i=1,j=0;i<n;++i)
	{
		while(s[j]!=s[i]&&j) j=nxt[j-1][id];
		if(s[j]==s[i]) nxt[i][id]=++j;
		else nxt[i][id]=0;
	}
}

vector<int> pos;
void comp(string s,string t,int id)
{
	int n=s.size(),m=t.size();
	for(int i=0,j=0;i<n;++i)
	{
		while(s[i]!=t[j]&&j) j=nxt[j-1][id];
		if(s[i]==t[j]) j++;
		//cout<<i<<" "<<j<<endl;
		if(j>=m) pos.push_back(i-m+1),j=nxt[j-1][id];
	}
}

string s[N][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][0]>>s[i][1],getnxt(s[i][0],s[i][0].size(),i);
	//string t;cin>>t;
	//comp(t,s[1][0],1);
	//for(int i:pos) cout<<i<<" ";
	while(q--)
	{
		int ans=0;
		string t1,t2;cin>>t1>>t2;
		for(int i=1;i<=n;++i)
		{
			pos.clear();
			comp(t1,s[i][0],i);
			for(int p:pos)
			{
				string t=t1.substr(0,p)+s[i][1]+t1.substr(p+s[i][0].size(),t1.size()-p-s[i][0].size());
				if(t==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
