#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,t={},n={};
    int o,i,x,y,maxi=-1;
    cin>>s;
    for(i=0;i<=s.size();i++)
    	if(isdigit(s[i]))
    	    t+=s[i];
	for(x=0;x<=t.size();x++)
	{
		maxi=0;
		for(y=0;y<=t.size()-x+1;y++)
			if(t[y]>maxi)
			{
			    maxi=t[y];
			    o=y;
			}
		t[o]=-2;
		n+=maxi;
	}
	cout<<n;
    return 0;
}