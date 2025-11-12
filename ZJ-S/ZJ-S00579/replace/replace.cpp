#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
string s,t,l1[N],l2[N],t1,t2;
int ans;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>l1[i]>>l2[i];
	}
	while(T--)
	{
		ans=0;
		cin>>s>>t;
		int fst=-1,ed=-1;
		int n=s.size(),m=t.size();
		for(int i=0;i<min(n,m);i++)
		{
			if(s[i]!=t[i])
			{
				fst=i;
				break;
			}
		}
		for(int i=0;i<min(n,m);i++)
		{
			if(s[n-1-i]!=t[m-1-i])
			{
				ed=i;
				break;
			}
		}
		if(fst==-1||ed==-1)
		{
			cout<<"0\n";
			continue;
		}
		t1=t2="";
		for(int i=fst;i<n-ed;i++)t1+=s[i];
		for(int i=fst;i<m-ed;i++)t2+=t[i];
		for(int i=1;i<=n;i++)
		{
			ans+=(l1[i]==t1)&&(l2[i]==t2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
5 1
10010
0 0 1 3 4
*/