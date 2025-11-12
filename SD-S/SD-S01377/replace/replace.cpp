#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
int n,q;
string s[200005][2];
int b[5000006];
unordered_map<string,unordered_map<string,bool> >mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	if(n<=1000&&q<=1000)
	{
		for(int i=1;i<=n;i++)
			mp[s[i][0]][s[i][1]]=1;
		while(q--)
		{
			string s1,s2;
			cin>>s1>>s2;
			int sz1=s1.size(),sz2=s2.size();
			if(sz1!=sz2)
			{
				cout<<"0\n";
				continue;
			}
			for(int i=0;i<=sz1+2;i++)
				b[i]=0;
			b[sz1]=1;
			for(int i=sz1-1;i>=0;i--)
			{
				if(s1[i]!=s2[i])
					break;
				if(s1[i]==s2[i])
					b[i]=1;
			}
			int ans=0;
			string e1="",e2="";
			for(int i=0;i<sz1;i++)
			{
				if(e1!=e2)
					break;
				string p1="",p2="";
				for(int j=i;j<sz1;j++)
				{
					p1+=s1[j];
					p2+=s2[j];
					if(mp[p1][p2]&&b[j+1])
						ans++;
				}
				e1+=s1[i],e2+=s2[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
// Thanks
}
