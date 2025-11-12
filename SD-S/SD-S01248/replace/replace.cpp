#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string t[200005][2],rev[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>t[i][0]>>t[i][1];
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		if(len<=200&&n<=100&&q<=100)
		{
			s1=" "+s1;
			string fir="";
			int ans=0;
			rev[len]="";
			for(int i=len;i>=2;i--) rev[i-1]=rev[i]+s1[i];
			for(int i=1;i<=len;i++) reverse(rev[i].begin(),rev[i].end());
			for(int i=1;i<=len;i++)
			{
				for(int j=1;j<=n;j++)
				{
					int siz=t[j][0].size();
					if(i+siz-1>len) continue;
					string s=s1.substr(i,siz);
					if(s!=t[j][0]) continue;
					string las=rev[i+siz-1];
					string res=fir+t[j][1]+las;
	//				cout<<res<<" "<<t[j][0]<<"\n";
					if(res==s2) ans++;
				}
				fir+=s1[i];
			}
			cout<<ans<<"\n";
			continue;			
		}
		cout<<0<<"\n";
	}
	return 0;
}
//	Ren5Jie4Di4Ling5%
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

