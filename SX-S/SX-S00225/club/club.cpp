#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,k[5];
bool f1,f2;
struct st
{
	long long s1,s2,s3,id1=1,id2=2,id3=3;
}a[100005];
bool cmp1(st x,st y)
{
	return x.s1>y.s1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	ans=0;
    	f1=1;
    	k[1]=0,k[2]=0,k[3]=0;
    	for(int i=1;i<=n;i++)
		{
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s2!=0||a[i].s3!=0) f1=0;
		}
		if(f1==1)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].s1;
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
        	{
     	    	if(a[i].s1<a[i].s2)
    		    {
    			    swap(a[i].s1,a[i].s2);
    				swap(a[i].id1,a[i].id2);
				}
				if(a[i].s2<a[i].s3)
    			{
    				swap(a[i].s2,a[i].s3);
    				swap(a[i].id2,a[i].id3);
				}
				if(a[i].s1<a[i].s2)
    			{
    				swap(a[i].s1,a[i].s2);
    				swap(a[i].id1,a[i].id2);
				}
			}
			for(int i=1;i<=n;i++)
    		{
    			if(k[a[i].id1]<n/2)
    			{
    				ans+=a[i].s1;
    				k[a[i].id1]++;
				}
				else if(k[a[i].id2]<n/2)
    			{
    				ans+=a[i].s2;
    				k[a[i].id2]++;
				}
				else
    			{
    				ans+=a[i].s3;
    				k[a[i].id3]++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
