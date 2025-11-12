#include<bits/stdc++.h>
using namespace std;
int sum=0,ans=0,cqy=0,a[10000],b[10000],c[10000];
int main()
{
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	int n,t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	    cin>>n;
	    for(int j=1;j<=n;j++)
	    {
	    	
	    	cin>>a[j]>>b[j]>>c[j];	
	    	if(a[j]>b[j]&&a[j]>c[j])
	    	 sum=a[1];
	    	 sum++;
	    	  if(b[j]>a[j]&&b[j]>c[j])
	    	 ans=b[1];
	    	 ans++;
	    	  if(c[j]>a[j]&&c[j]>b[j])
	    	 cqy=c[1];
	    	 cqy++;
	    }
	    cout<<sum+ans+cqy;
	}
	
	fclose(stdin);
	fclose(stdout);
}