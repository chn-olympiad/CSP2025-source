#include <bits/stdc++.h>
using namespace std;
int t,n,a[10001][4],ans = 0,maxx=0,cnt=0,maxxx=0,sum=0,maxxxx=0;
int m;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
    while(t--)
    {
    	cin >> n;
    	for(int i = 1;i <= n;i++)
    	{
    		for(int j = 1;j <= 3;j++)
    		{
    			cin >> a[i][j];
			}
		}
	    for(int i = 1;i <= n;i++)
	    {
		    for(int j = 1;j <= n;j++)
 	        {
		        ans = n / 2;
		        maxx = max(maxx,a[j][1]);
	        }
		    if(ans!=0)
	        {
	            cnt += maxx;
	            if(maxx == a[i][1])
	            {
	        	    a[i][1] = 0;
			    }
	            ans--;
	            m++;
            }
            else
            {
        	    for(int j = 1;j <= n;j++)
 	            {
 	        	    sum = n / 2;
		            maxxx = max(maxxx,a[j][2]);
	            } 
			    if(sum != 0) 
			    {
				    cnt += maxxx;
	                if(maxxx == a[i][2])
	                {
	        	        a[i][2] = 0;
			        } 
			        sum--;
			        m++;
			    }	
		    }
		    if(m < n)
		    {
		    	for(int j = 1;j <= n;j++)
		        {
			        maxxxx = max(a[j][3],maxxxx);
		        }
		        cnt += maxxxx;
		        if(maxxx == a[i][2])
	            {
	                a[i][3] = 0;
		        } 		    	
			}
	    }
        cout << cnt << endl;
        cnt = 0;
	}

	return 0;
}
