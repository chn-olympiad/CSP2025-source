#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int n,q;
string s1[1145140],s2[1145140],q1,q2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>q1>>q2;
		for(int j=1;j<=n;j++)
		{
			int ps=0;
			string fq=q1;
			ps=fq.find(s1[j]);
			if(ps==-1) continue;
			fq.replace(ps,s1[j].size(),s2[j]);
			if(fq==q2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
*/