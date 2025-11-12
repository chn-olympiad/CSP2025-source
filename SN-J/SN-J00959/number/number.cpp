#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=1;i<=s.length()+1;i++)
	{
	    for(int j=1;j<=s.length()+1;j++)
		{
		    if(s[j]>s[j-1])
		    {
		        swap(s[j-1],s[j]);	
		    }			
		}		
	}
	cout<<s;
	return 0;
}

