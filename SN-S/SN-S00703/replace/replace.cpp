#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

const int N=2e5+5,M=5e6+5;

int n,q,tot,ans;
string t1,t2;
int trie[M][26],f[M],fail[M];
string s[N][2];

void insert(string a,int id)
{
	int len=a.size(),u=0;
	for(int i=0;i<len;i++)
	{
		int c=a[i]-'a';
		if(!trie[u][c])
			trie[u][c]=++tot;
		u=trie[u][c];
	}
	f[u]=id;
}

void getfail()
{
	queue<int> q;
	for(int i=0;i<26;i++)
		if(trie[0][i])
			q.push(trie[0][i]);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(trie[u][i])
			{
				fail[trie[u][i]]=trie[fail[u]][i];
				q.push(trie[u][i]);
			}
			else
			{
				trie[u][i]=trie[fail[u]][i];
			}
		}
	}
}

void Trie()
{
	int len=t1.size(),u=0;
	for(int i=0;i<len;i++)
	{
		int c=t1[i]-'a';
		u=trie[u][c];
		int t=u;
		while(t)
		{
			if(f[t])
			{
				int id=f[t];
				int l=i-s[id][1].size()+1;
				string a=t1;
				for(int j=l;j<=i;j++)
					a[j]=s[id][1][j-l];
				if(a==t2)
					ans++;
			}
			t=fail[t];
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		insert(s[i][0],i);
	}
	getfail();
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		ans=0;
		Trie(); 
		cout<<ans<<endl;
	}
	return 0;
}
