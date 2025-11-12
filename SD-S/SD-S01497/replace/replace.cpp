#include<iostream>
#include<vector>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
const int bas=233;
const int ma=993244853;
const int mb=1e9+9;
int n,q;
struct nod
{
	string s; int len;
	vector <int> wa,wb;
	void ini()
	{
		cin>>s,len=s.size();
		wa.resize(len+2),wb.resize(len+2);
	}
}sa[N],sb[N],ta,tb;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) sa[i].ini(),sb[i].ini();
	while(q--)
	{
		ta.ini(),tb.ini(); int l=-1,r=-1,len=ta.len;
		if(ta.len!=tb.len) {cout<<0<<'\n'; continue;}
		for(int i=0;i<len;i++) if(ta.s[i]!=tb.s[i]) r=i;
		for(int i=len-1;i>=0;i--) if(ta.s[i]!=tb.s[i]) l=i;
	}
	return 0;
}
