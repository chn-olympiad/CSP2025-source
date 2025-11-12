#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q*n<=1000000)
	{
		for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
		while(q--)
		{
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()) cout<<0<<endl;
			else
			{
				int ans=0;
				for(int i=1;i<=n;i++)
				{
					if(t1.find(s1[i])!=-1)
					{
						int pos=t1.find(s1[i]);
						string temp=t1.substr(0,pos);
						temp+=s2[i];
						temp+=t1.substr(pos+s1[i].size());
						if(temp==t2) ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	else//special form
	{
		
	}
	return 0;
}
