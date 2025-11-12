// 许景焱 SN-S00654 西安铁一中滨河高级中学
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int maxn=200000;

struct Rep
{
	string s1,s2;
	int len,pos1,pos2;
};

int n,q,len,pos1,pos2,ans;
string t1,t2,temp1,temp2;
Rep s[maxn+5];

bool cmp(Rep a,Rep b)
{
	return a.len>b.len;
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>s[i].s1>>s[i].s2;
		s[i].len=s[i].s1.length();
		for(int j=0; j<s[i].len; j++)
			if(s[i].s1[j]!=s[i].s2[j])
			{
				s[i].pos1=j;
				break;
			}
		for(int j=s[i].len-1; j>=0; j--)
			if(s[i].s1[j]!=s[i].s2[j])
			{
				s[i].pos2=j;
				break;
			}
	}
	sort(s+1,s+n+1,cmp);
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		len=t1.length();
		if(len<s[n].len||len!=t2.length())
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0; i<len; i++)
			if(t1[i]!=t2[i])
			{
				pos1=i;
				break;
			}
		for(int i=len-1; i>=0; i--)
			if(t1[i]!=t2[i])
			{
				pos2=i;
				break;
			}
		for(int i=1; i<=n; i++)
		{
			if(s[i].len<pos2-pos1+1)
				break;
			if(s[i].len>len||s[i].pos1>pos1||s[i].len-s[i].pos2>len-pos2||s[i].pos2-s[i].pos1!=pos2-pos1)
				continue;
			bool check=true;
			for(int j=0; j<s[i].len&&check; j++)
				if(t1[pos1+j-s[i].pos1]!=s[i].s1[j])
				{
					check=false;
					break;
				}
			for(int j=pos2-pos1; j>=0&&check; j--)
				if(t2[pos1+j]!=s[i].s2[s[i].pos1+j])
				{
					check=false;
					break;
				}
			if(check)
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
