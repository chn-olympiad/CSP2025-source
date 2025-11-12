#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
int b[501],c[501];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,js=0;
	string a;
	cin>>n;
	cin>>m;
    cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
    }
	for(int i=1;i<=n-1;i++)
	 {
	 	for(int j=n;j>=i+1;j--)
	 	 {
	 	 	if(c[j]>c[i])
	 	 	 {
	 	 	 	swap(c[j],c[i]);
			   }
		  }
	}
	for(int i=0;i<=n-1;i++)
	{
		int j=0;
		if (a[i]==1) js+=1;
		b[j]=i;
		j+=1;
	}
	if (js<m)
	{
		cout<<0;
	}
	else
	{
	   ll zh=1;
	   for(int i=0;i<=js*js;i++)
	    {
	    	for(int j=js-1;j>=0;j--)
	    	{
	    		ll js2=0;
				if((1<<j)&&i==1)
	    		 {
	    		 	js2+=1;ll js3=0;
	    		 	for(int k=1;k<=n;k++)
	    		 	{
						if(c[k]>b[js2-1])
	    		 		{
	    		 			js3++;
					    }
					 }
					zh*=(js3-js2+1)%mod;
				 }
			}
		}
	   cout<<zh<<endl;
	}
    fclose(stdin);fclose(stdout);
	return 0;

}

