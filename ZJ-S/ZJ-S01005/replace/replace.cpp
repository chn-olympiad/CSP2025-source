#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1001],b[1001],x,y;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>b[i];
	while(q--)
	{
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<x.size()-a[i].size()+1;j++)
			{
				int flag=0;
				for(int k=j;k<=j+a[i].size()-1;k++)
			      if(a[i][k-j]!=x[k]||b[i][k-j]!=y[k])
			       {
			       	flag=1;
			       	break;
			       }
			    if(!flag)
			    {
			    	int fl=0;
			    	for(int k=0;k<j;k++)
			    	  if(x[k]!=y[k])
					  {
					  	fl=1;
					  	break;
					  }
			    	for(int k=j+a[i].size();k<x.size();k++)
			    	  if(x[k]!=y[k])
					  {
					  	fl=1;
					  	break;
					  }
					if(fl==1)continue;
//			    	cout<<i<<' '<<j<<endl;
			    	cnt++;
			    	break;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
