#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
string s[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	long long ans=0;
	while(q--)
	{
		string ss,ot;
		cin>>ss>>ot;
		if(ss.size()!=ot.size()) continue;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			while(1)
			{
				int place=ss.find(s[i][0]);
				if(place>ss.size()||place<0) break; 
			//	cout<<place<<endl;
				bool flag=true;
				for(int j=0;j<place;j++)
				{
					if(ss[j]!=ot[j]){
						flag=false;
						break;
					}
				}
				if(flag)
				{
					for(int j=place;j<place+s[i][0].size();j++)
					{
						if(s[i][1][j-place]!=ot[j]){
							flag=false;
							break;
						}
					}
				}
				if(flag)
				{	
					for(int j=place+s[i][0].size();j<ot.size();j++)
					{
						if(ss[j]!=ot[j]){
							flag=false;
							break;
						}
					}
				}
				if(flag)
				{
					ans++;
				}
				if(ss[place]!=ot[place])
				{
					break;
				}
				ss[place]=' ',ot[place]=' ';
			}
		}
		cout<<ans<<endl;
	//	cout<<endl;
	}
	return 0;
 } 
