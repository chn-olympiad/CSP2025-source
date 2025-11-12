#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;

string s1[N],s2[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t1.size()-s1.size()+1;j++)
			{
				if(t1.substr(j,s1.size())==s1&&t2.substr(j,s2.size())==s2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
