#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int T,n;
struct Man
{
	int a,b,c;
}M[100010];
int mid(int a,int b,int c)
{
	return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}
int _max(int a,int b,int c)
{
	return max(a,max(b,c));
}
bool cmp(Man a,Man b)
{
	return _max(a.a,a.b,a.c)-mid(a.a,a.b,a.c)>_max(b.a,b.b,b.c)-mid(b.a,b.b,b.c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>M[i].a>>M[i].b>>M[i].c;
		}
	    sort(M+1,M+n+1,cmp);
	    int ca=0,cb=0,cc=0;
	    int ans=0;
	    for(int i=1;i<=n;i++)
	    {
		    int a=M[i].a,b=M[i].b,c=M[i].c;
		    if(_max(a,b,c)==a&&ca<n/2)
		    {
		    	ans+=a;
		    	ca++;
		    	continue;
			}
		
		    if(_max(a,b,c)==b&&cb<n/2)
		    {
		    	ans+=b;
		    	cb++;
		    	continue;
	    	}
		    if(_max(a,b,c)==c&&cc<n/2)
		    {
		    	ans+=c;
		    	cc++;
		    	continue;
		    }
	    	ans+=mid(a,b,c);
	    	if(mid(a,b,c)==a)
	    	{
	    		ca++;
	    	}
	   	    else if(mid(a,b,c)==b)
	    	{
	    		cb++;
	    	}
	     	else if(mid(a,b,c)==c)
	     	{
	      		cc++;
	     	}
	    }
	    cout<<ans<<'\n';
    }
	return 0;
}