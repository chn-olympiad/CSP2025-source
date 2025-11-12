#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj[105];
	cin >> n >> m;
	for (int i = 0;i < n * m;i++)
	{
	    cin >> cj[i];
	}
	int me = cj[0];
	
	sort (cj,cj+n*m,cmp);
	
	//for (int i = 0;i < n * m;i++)
	//{
	//    cout << cj[i] << " ";
	//}
	//cout << endl;
	
	int x = 1,y= 1,dq = 0;
	
	for(int i = 1;i <= n;i++)
	{
		if (i % 2 == 1)
		{
			y = 1;
			for (int j = 0;j < m;j++)
			{
		    	if (cj[dq] == me)
	        	{
		        	cout << x << " " << y;
		        	return 0;
	        	}
	        	
	        	//cout << cj[dq] << " " << x << " " << y << endl;
	        	
	        	dq++;y++;
		    }
		}
		else
		{
			y = m;
			for (int j = 0;j < m;j++)
			{ 
		    	if (cj[dq] == me)
	        	{
		        	cout << x << " " << y;
		        	return 0;
	        	}
	        	
	        	//cout << cj[dq] << " " << x << " " << y << endl;
	        	
	        	dq++;y--;
		    }
		}
		
		x++;
	} 
	
	return 0;
}
