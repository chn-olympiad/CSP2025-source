#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,l[N],r[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='b')
				break;
			l[i]++;
		}
		l[i]=2*l[i]-s.size()+1;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='b')
				break;
			r[i]++;
		}
		r[i]=2*r[i]-s.size()+1;
	}
	for(int i=1,tl,tr;i<=q;i++)
	{
		tl=0,tr=0;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='b')
				break;
			tl++;
		}
		tl=2*tl-s.size()+1;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='b')
				break;
			tr++;
		}
		tr=2*r[i]-s.size()+1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(l[i]+tr==r[i]+tl)
			{
				ans++;
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
