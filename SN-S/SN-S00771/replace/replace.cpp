#include<bits/stdc++.h>
using namespace std;
int n,q;
string b,c;
int x;
int y;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		cin>>b>>c;
	}
	for(int i=1;i<=q;i++)
	{
		x=0;y=0;
		cin>>b>>c;
		for(int j=0;j<b.length();j++)
		{
			if(b[j]!=c[j]) x++;
			else y++;
		}
		cout<<min(x,y)<<endl;
		
	}
	return 0;
	
 } 
