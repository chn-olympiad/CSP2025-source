#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int l;
	int r;
	cin>>m>>n;
    int a[m][n];
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
		s[0]=1;
		s[1]=2;
	for(int i=1;i<=n*m;i++)
	{
	    s[i]=i;
	    cout<<s[i];
	}
	return 0;
}

