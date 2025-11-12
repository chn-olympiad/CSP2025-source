#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
const int yd=5000005;
struct node
{
	int l,r;
};
vector<node>f[10000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int t1=s1.find("b");
		int t2=s2.find("b");
		int lef=min(t1,t2);
		int ri=s1.size()-max(t1,t2);
		f[t1-t2+yd].push_back({lef,ri});
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int t1=s1.find("b");
		int t2=s2.find("b");
		int lef=min(t1,t2);
		int ri=s1.size()-max(t1,t2);
		int cnt=0;
		for(node t:f[t1-t2+yd])
		{
			if(lef>=t.l&&ri>=t.r)cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
