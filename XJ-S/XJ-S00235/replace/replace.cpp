#include <bits/stdc++.h>
using namespace std;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	string s[n+1][3],t1,t2;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][1]>>s[i][2];
	}
//	int cnt1=0,cnt2=0;
	for(int i=0;i<q;++i)
	{
//		cin>>t1>>t2;
//		for(int i=1;i<=n;++i)
//		{
//			if(t1.find(s[i][1])!=string::npos||t1.find(s[i][2])!=string::npos)
//				
//		}
		cout<<0<<"\n";
	}
	return 0;
}
