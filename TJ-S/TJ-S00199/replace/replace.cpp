#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s1[10005],s2[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	string a,b,c;
	string a1;
	int l;
	while(q--)
	{
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++)
		{
	    	l=s1[i].size();
	    	for(int j=0;j+l<=a.size();j++)
	    	{
		    	a1=a;
	    		c=a.substr(j,l);
	    		if(c==s1[i])
	    			for(int k=0;k<=c.size()-1;k++)
	    				a1[j+k]=s2[i][k];
	    		
	    	    if(a1==b) ans++;
			}
		}
    	cout<<ans<<endl;
	}
	return 0;
}

