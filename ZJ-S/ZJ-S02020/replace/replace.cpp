#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--)
	{
		string ta,tb;
		cin>>ta>>tb;
		int ans=0;
		for(int i=0;i<ta.size();i++)
		{
			for(int j=i;j<ta.size();j++)
			{
				string stmp="";
				for(int k=0;k<i;k++)stmp+=ta[k];
				string stmp1="";
				for(int k=i;k<=j;k++)stmp1+=ta[k];
				for(int t=1;t<=n;t++)
				{
					if(stmp1==s1[t])
					{
						string stmp2=stmp;
						stmp2+=s2[t];
						for(int k=j+1;k<ta.size();k++)stmp2+=ta[k];
						if(stmp2==tb)ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
