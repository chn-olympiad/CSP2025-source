#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			string tt=t1;
			int pos=tt.find(s1[i]);
			if(pos!=-1)
			{
				tt.erase(pos,s1[i].size());
				tt.insert(pos,s2[i]);
				if(tt==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
