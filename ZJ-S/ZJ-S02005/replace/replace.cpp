#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+101;
int n,q;
string s[N][3],S1,S2;
int main()
{
	Fcin;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		int ans=0;
		cin>>S1>>S2;
		for(int i=1;i<=n;++i)
		{
			string p="";
			int len=s[i][1].size();
			for(int j=0;j<S1.size();++j)
			{
				string t=S1.substr(j,len);
				if(t==s[i][1])
				{
					string xx=p+s[i][2],xy=S2.substr(0,j+len);
					if(xx==xy) ans++;
				}
				p+=S1[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
