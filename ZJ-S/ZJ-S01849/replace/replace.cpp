#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
string s[N][2];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int beg,ed=0;
		for(int i=0;i<x.size();i++)
		{
			if(x[i]!=y[i])
			{
				if(!beg)
					beg=i;
				ed=i;
			}
		}
		string dx,dy="";
		for(int i=beg;i<=ed;i++)
		{
			dx+=x[i];
			dy+=y[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][0].find(dx)&&s[i][1].find(dy))
				ans++;
		}
		cout<<beg<<"    "<<ed<<endl<<endl;
		cout<<ans<<"\n";
	}
	return 0;
}