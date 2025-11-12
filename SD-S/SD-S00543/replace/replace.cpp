#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
int find(string s,string a)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]==a[0])
		{
			int flag=0;
			for (int j=i;j<=min(i+a.size()-1,s.size()-1);j++)
			{
				if (s[j]!=a[j-i])
				{
					flag=1;
					break;
				}
			}
			if (flag==0) return i;
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while (q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int st=find(s1,a[i]);
			if (st!=-1)
			{
				string mid=s1;
				for (int j=st;j<=st+a[i].size()-1;j++)
				{
					char x=b[i][j-st];
					mid[j]=x;
				}
				if (mid==s2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

