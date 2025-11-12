#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n[10000] ;
	int lonth = 0;
	for(int i = 0;i <= 10000;i ++)
	{
	    cin >> n[i];
	    lonth ++;
	}
	if(n[0] != 0)
	{
		cout << n[0]
	}
	else
	{
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 9)
	        {
	        	cout << n[i]; 
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 8)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 7)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 6)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 5)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 4)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 3)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 2)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 1)
	        {
	        	cout << n[i];
	        }
	    }
	    for(int i = 0;i <= lonth;i ++)
	    {
	        if(n[i] == 0)
	        {
	        	cout << n[i];
	        }
	    }
	}
    return 0;
}
