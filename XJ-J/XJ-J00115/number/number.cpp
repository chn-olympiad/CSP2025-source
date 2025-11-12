#include<bits/stdc++.h>
using namespace std;
string a,t;long long int k=0,b[1000005];
int main()
{
    //freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	if(a.size()==1&&a[0]>='0'&&a[0]<='9')
	{
		cout<<a[0];
		return 0;
	}
	if(a.size()==2&&a[0]>='0'&&a[0]<='9'&&a[1]>='0'&&a[1]<='9')
	{
		if(a[0]>a[1])
		cout<<a[0]<<a[1];
		else
		cout<<a[1]<<a[0];
		return 0;
	}
	else
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				b[a[i]-'0']++;
			}
		}
	    for(int i=100005;i>=0;i--)
	    {
	    	if(b[i]!=0)
	    	{
	    		int n=b[i];
	    		while(n!=0)
	    		{
	    			t=i+'0';
	    			cout<<t;
	    			n--;
				}
			}
	    }
	}
	
	return 0;
 } 
