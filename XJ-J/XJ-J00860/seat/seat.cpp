#include<bits/stdc++.h>                                                                                                                                   
using namespace std;
int main()
{
	int i,n,m,s[105],t,xiao,ans,c,r;
	cin>>n>>m;
	t=n*m;
	for(i=1;i<=t;i++)
	cin>>s[i];                                         
	
	xiao=s[1];
	sort(s,s+1+t);
	
	for(i=t;i>=1;i--)
	{                                                                                                                                                                                                                         
		if(s[i]==xiao)
		ans=i;
	}
	
	if(ans<=n)
	{
		c=1;
		r=ans;
	}
	if
	cout<<c<<" "<<r;
	
	return 0;
}       
