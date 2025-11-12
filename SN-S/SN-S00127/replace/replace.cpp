#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n, q;
string s1[maxn], s2[maxn], q1[2005][2005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}	
	for(int i=1;i<=q;i++)
	{
		string t1, t2;
		cin>>t1>>t2;
		int len1=t1.size(), len2=t2.size();
		if(len1!=len2)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<len1;i++)
		{
			for(int j=1;i+j-1<len1;j++)
			{
				q1[i][j]=t1.substr(i, j);
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int len=s1[j].size();
			for(int l=0;l+len-1<len1;l++)
			{
				if(q1[l][len]!=s1[j]) continue;
				string tmp=q1[0][l]+s2[j]+q1[l+len][len1-len-l];
				if(tmp==t2) ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
