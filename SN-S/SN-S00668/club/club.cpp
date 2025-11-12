#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100005],b[100005],c[100005],d[100005],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
    cin>>t;
    while(t--)
	{
    	cin>>n;
    	ans=0;
    	for(int i=0,i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2)
		{
			cout<<max(a[0],max(b[0],c[0]))+maz(a[1]max[b[1],c[1]])<<endl;
		}else 
		{
		    sort(b,b+n);
		    for(int i=n-1;i>(n+1)/2;i--)ans+=b[i];
		    cout<<ans<<endl;
		}
	}
	return 0;
}
