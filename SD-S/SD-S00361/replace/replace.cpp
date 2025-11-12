#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=2e5;
int n,q,i,j,cnt;
string s[MX+10][3],st,ts;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		cin>>st>>ts;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			int lens=s[i][1].size();
			int lent=st.size();
			for(j=0;j<=lent-lens;j++)
			{
				string x=st.substr(0,j);
				string str=st.substr(j,lens);
				string y=st.substr(j+lens,lent-j-lens);
				x+=s[i][2];x+=y;
				if(str==s[i][1]&&x==ts)cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
