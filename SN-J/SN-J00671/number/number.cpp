#include<bits/stdc++.h>
using namespace std;
int r=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",sdout);
	int s,i,b=0,c;
	cin>>s;
	for(i=0;i<'s';i++)
	{
		a[i]=s%10;
	    c=a[i];
	    if(b<=c)
	    r+=c*(s-i);
		else
		r+=b*(s-i),b=c;
    }
    cout<<r;
    return 0;
}
