#include<bits/stdc++.h>
const int slen=1e3+10;
using namespace std;
int n,q;
string a[slen][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i][0]>>a[i][1];
	for(int o=1;o<=q;++o)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;++i)
		{
			if(a[i][0]==t1&&a[i][1]==t2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}