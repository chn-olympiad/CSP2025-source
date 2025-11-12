#include<bits/stdc++.h>
using namespace std;
string p;
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	cin>>p;
	
	for(int i=0;i<p.size();i++)
	{
		for(int j=0;j<p.size();j++)
		{
			if(p[j]<p[j+1])
			{
				int q;
				q=p[j+1];
				p[j+1]=p[j];
				p[j]=q;
			}
		}
	}
	
	for(int i=0;i<p.size();i++)
	{
		if(p[i]=='1'||p[i]=='2'||p[i]=='3'||p[i]=='4'||p[i]=='5'||p[i]=='6'||p[i]=='7'||p[i]=='8'||p[i]=='9'||p[i]=='0')
		{
			cout<<p[i]-'0';
		}
	}
	
	return 0;
 } 
