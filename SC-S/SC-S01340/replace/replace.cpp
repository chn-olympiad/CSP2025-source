#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,q;
string s[maxn][2],t[maxn][2];
vector<int> nxt[maxn];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++)
	{
		int x=s[i][0].size();
		nxt[i].push_back(0);nxt[i].push_back(0);
		for(int j=2,k=0;j<=x;j++)
		{
//			cout<<j<<' '<<k<<endl;
			while(k&&s[i][0][j-1]!=s[i][0][k])k=nxt[i][k-1];
//			cout<<endl;
			if(s[i][0][j-1]==s[i][0][k])k++;
			nxt[i].push_back(k);
		}
//		for(int j=1;j<=x;j++)cout<<nxt[i][j]<<' ';cout<<endl;
	}
//	cout<<"kmp"<<endl;
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		string a=t[i][0],b=t[i][1];
		for(int j=1;j<=n;j++)
		{
			int x=a.size(),y=b.size();
//			if(a!=b)cout<<0<<endl;
			int k=1;
			for(int l=0;k<=x;k++)
			{
				while(l&&s[j][0][l]!=t[i][0][k-1])l=nxt[j][l-1];
				if(s[j][0][l]==t[i][0][k-1])l++;
				if(l==s[j][0].size())break;
			}
			if(k<=x)
			{
				k-=s[j][0].size();
				t[i][0].replace(k,s[j][0].size(),s[j][1]);
				if(t[i][0]==t[i][1])cnt++;
				t[i][0].replace(k,s[j][0].size(),s[j][0]);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
