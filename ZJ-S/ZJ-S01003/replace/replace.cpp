#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,maxlen;
string s1,s2,t1,t2,s[2100][2100];
map<string,string> a;
string check(int x,int y)
{
	if(x>y) return "";
	else return s[x][y];
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int k=s1.size();
		a[s1]=s2;
		maxlen=max(maxlen,k);
	}
	while(q--)
	{
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<=t1.size()-1;i++)
		{
			s[i][i]=t1[i];
			for(int j=i+1;j<=t1.size()-1;j++) s[i][j]=s[i][j-1]+t1[j];
		}
		for(int i=0;i<=t1.size()-1;i++)
			for(int j=i;j<=t1.size()-1;j++)
		if(a[s[i][j]]!="")
		{
			if(check(0,i-1)+a[s[i][j]]+check(j+1,t1.size()-1)==t2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
