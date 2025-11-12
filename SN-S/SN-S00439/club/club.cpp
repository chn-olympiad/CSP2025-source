#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
long long int a[20005];
long long int b[20005];
long long int c[20005];
long long int max1[20005];
long long int max2[20005];
using namespace std;
int main()
{ 
//毛绍和 SN-00439 陕西省安康中学 
	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
   
    long long int ans=0;
    int t,n=0;
    cin>>t;
    int an,bn,cn=0;
    for(int i=0;i<t;i++)
    {   
    	cin>>n;
    	for(int j=0;j<n;j++)
    	{   
   		    cin>>a[j]>>b[j]>>c[j];
		}
        for(int i=0;i<n;i++)
        {   
        	max1[i]=(max(a[i],max(b[i],c[i])));
        	max2[i]=(min(max(b[i],c[i]),max(a[i],b[i])));
        	if((max(a[i],max(b[i],c[i]))==a[i]){
        		an++;
			}
			else if((max(a[i],max(b[i],c[i]))==b[i]){
				bn++;
			}
			else {
				cn++;
			}
            if(an<(n/2)&&bn<(n/2)&&cn<(n/2))for (int i=0;i<n;i++)ans+=max[i];
            if(an>(n/2))for (int i=0;i<n;i++)ans+=max[];
		}
        
		   cout<<ans<<endl;
		   ans=0;
			}
    	    
		   

	return 0;
}
