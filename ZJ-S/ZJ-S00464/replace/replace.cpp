#include<iostream>
#include<string>
using namespace std;
int n,q,c=1,ans;
string a[10000][2],s1,s2,s3;
void Q()
{
	cin>>s1>>s2;
	for(int b=1;b<=q;b++)
	{
		for(int j=0;j<=s1.size()-a[b][0].size();j++)
	    {
	    	s3=s1;
	    	c=1;
	    	for(int k=j;k<=a[b][0].size()-1;k++)
	    	{
	    		if(s1[k+j+1]!=a[b][0][k])
	    		{
	    			c=0;
	    			continue;
				}
			}
	    	for(int k=j;k<=a[b][0].size()+j-1&&c;k++)
	    	{
	    		s3[k]=a[b][1][k-j];
			}
			for(int k=0;k<=s1.size()-1&&c;k++)
			{
				if(s3[k]!=s2[k])
				{
					c=0;
					continue;
				}
			}
			ans+=c;
	    }
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		Q();
	}
}
