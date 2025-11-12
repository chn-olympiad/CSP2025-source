#include <bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main()
{
//	string s="sss";
//	string s1="s";
//	cout << s.find(s1);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin >> n >> q;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i]>>b[i];
	}
	while(q--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			if(s1.find(a[i])==s2.find(b[i]))
			{
				string s11=s1,s22=s2;
				long long as1=s11.find(a[i]),bs1=s22.find(b[i]);
				string ss=s11.substr(0,as1);
				string ss1=s22.substr(0,bs1);
				string sss=s11.substr(as1+a[i].size(),s11.size()-(as1+a[i].size()));
				string sss1=s22.substr(bs1+b[i].size(),s22.size()-(bs1+b[i].size()));
				//cout << ss <<" "<< ss1<<endl;
				if(ss==ss1&&sss==sss1) ans++;
			}
		}
		cout << ans<<endl;
	}
	return 0;
}
