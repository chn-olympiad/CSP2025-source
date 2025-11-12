#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum = 0;
	int sum1 = 0;
	int x , y , z  = 0;
	int cnt = 0;
	int m,n = 0;
	string q;
	if(s.size() == 1)
	{
		cout<<s;
	}
	
	else
	{
		for(int i = 0; i<=s.size(); i++) 
	    {
		    a[i] = s[i] - 48;
	     	sum = i;	
	     	//cout<<a[i]<<" ";
	    }
       	//cout<<sum<<" ";
	    for(int i = 0 ; i<sum; i++)
	    {
		    if(a[i]<=9)
		    {
		    	b[i] = a[i];
		    	if(a[i] == 0)
		    	x++;
			}
		     if(a[i]>9)
		    {
			   b[i] = 0;
			  sum1 ++;
		    }
	    }
		m = sum-sum1;
		//cout<<m<<endl;
		while(m)
		{
			for(int i = 0; i<sum; i++ )
		    {
			   if(b[i]<b[i+1])
	    	   {
	    		y = b[i+1];
	    	   }
	        }
	        cout<<y<<" ";
	        c[cnt] = y;
	        //cout<<c[cnt];
	        for(int i= 0; i<sum; i++)
		    {
				if(c[cnt] == b[i])
				{
					b[i] = 0;
				}
		    }
			y = 0;
			cnt++;
			m--;
			//cout<<c[cnt];
		}
		for(int i = 0; i<cnt; i++)
		{
			q[i] == c[cnt];
		}
		//cout<<q;
		for(int i = 0; i<sum1; i++)
		{
			q[cnt+1] = 0;
		}
			//cout<<q; 
		
	}
	return 0;
	
}
