#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int t[N],s[30];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string t,t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int len1=t1.size(),ans=0;
		for(int i=1;i<=n;i++)
		{
			int len2=s1[i].size();
			if(len1>=len2)
			{
				for(int l=0,r=len2-1;r<len1;l++,r++)
				{
					t=t1.substr(0,l);
					for(int j=l;j<=r;j++)
					{
						if(s1[i][j-l]!=t1[j])
						{
							break;
						}
						t+=s2[i][j-l];
					}
					t+=t1.substr(r+1);
				//	cout<<i<<" "<<l<<" "<<t<<endl;
					if(t==t2)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

