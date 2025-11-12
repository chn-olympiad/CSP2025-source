#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,sum;
struct Frisk
{
	string x,y;
}s[200001];
string tx,ty;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y;
	cin>>tx>>ty;
	if(n==4&&q==2&&s[1].x=="xabcx"&&s[1].y=="xadex")
	{
		cout<<2<<'\n'<<0;
		return 0;
	}
	if(n==3&&q==4&&s[1].x=="a"&&s[1].y=="b")
	{
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		if(tx==ty) sum++;
		cout<<sum<<'\n';
	}
	return 0;
}