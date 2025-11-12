#include<bits/stdc++.h>
using namespace std;

void io()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int maxn = 2e5+5;
int n,q,ans;
string s[maxn][2],t1,t2;
bool ask(string a,string b)
{
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] != b[i])return 0;
	}
	return 1;
}
bool cck(int a,int b)
{
	string t = "";
	for(int i = a; i < a+s[b][1].size(); i++)
	{
		t = t+t1[i];
	}
	//cout<<a<<' '<<b<<' '<<t<<' '<<s[b][0]<<"\n";
	return ask(t,s[b][0]);
}
void cnt(int x)
{
	for(int i = 0; i < t1.size()-s[x][0].size()+1; i++)
	{
		if(cck(i,x))
		{
			string t = t1;
			for(int j = 0; j < s[x][0].size(); j++)
	        {
		        t[j+i] = s[x][1][j];
			}
			//cout<<"IAKIOI "<<t<<"\n";
			if(ask(t,t2))ans++;
		}
	}
}
signed main()
{
	io();
	cin >>n>>q;
	for(int i = 1; i <= n; i++)
	{
		cin >>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		ans = 0;
		cin >>t1>>t2;
		for(int i = 1; i <= n; i++)
		{
			cnt(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}