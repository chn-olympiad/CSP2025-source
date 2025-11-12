#include<bits/stdc++.h>
using namespace std;
int n,q,m,cnt,p,mx,mn;
string s1[200010],s2[200010],st1,st2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		cin>>st1>>st2;
		m=st1.size();cnt=0;mx=-1;mn=m+1;
		if(m!=st2.size()) {cout<<0<<endl;continue;}
		for(int j=0;j<m;j++)
			if(st1[j]!=st2[j])
			{
				mx=max(mx,j);
				mn=min(mn,j);
			}
		for(int j=1;j<=n;j++)
		{
			int k=st1.find(s1[j]);
			if(k>=0&&k<m)
			{
				p=0;
				while(p<s2[j].size()&&st2[k+p]==s2[j][p]) p++;
				if(mx==-1&&p==s2[j].size()) cnt++;
				else if(p==s2[j].size()&&mn>=k&&mx<=k+p-1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}