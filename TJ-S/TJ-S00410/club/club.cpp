#include<bits/stdc++.h>
using namespace std;
long long t,n; 
struct node{
	long long a1,a2,a3,x,da;
}a[100001];
bool cmp1(node x,node y)
{
	return x.a1>y.a1;
}
bool cmp2(node x,node y)
{
	return x.a2>y.a2;
}
bool cmp3(node x,node y)
{
	return x.a3>y.a3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long ans=0;
		long long x1=0,x2=0,x3=0;
		cin>>n;
		if(n==2)
		{	
			long long maxxx=-1e9;
			long long aa[3][4]={{},{}};
			for(long long i=1;i<=2;i++)
			{
				
				for(long long j=1;j<=3;j++)
				{
					cin>>aa[i][j];
					//cout<<aa[i][j]<<' ';
				} 
				//cout<<endl;
	 		}
	 		long long aa1=0,aa2=0,aa3=0;
		 aa1=max(aa[1][1]+aa[2][2],aa[1][1]+aa[2][3]);
	 		//cout<<aa1<<' ';
	 		aa2=max(aa[1][2]+aa[2][1],aa[1][2]+aa[2][3]);
	 		//cout<<aa2<<' ';
	 		aa3=max(aa[1][3]+aa[2][2],aa[1][3]+aa[2][1]);
	 		//cout<<aa3<<' ';
	 		//cout<<aa[1][4]<<' '<<aa[2][1]<<' ';
	 		ans=max(aa1,max(aa2,aa3));
	 		cout<<ans<<endl;
		 } 
	else 
	{
		
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
			//a[i].maxx=maxx;
			if(maxx==a[i].a1){/*a[i].x=1;*/x1++;a[i].da=maxx;}
			else if(maxx==a[i].a2){/*a[i].x=2;*/x2++;a[i].da=maxx;}
			else if(maxx==a[i].a3){/*a[i].x=3;*/x3++;a[i].da=maxx;}
	 	}
		for(long long i=1;i<=n;i++)
		{
			if(x1>n/2)
			{
				sort(a+1,a+n+1,cmp1);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=a[i].a1;
				 } 
				for(long long i=n/2+1;i<=n;i++)
				{
					ans+=max(a[i].a3,a[i].a2);
				}
			}
			 else if(x2>n/2)
			{
				sort(a+1,a+n+1,cmp2);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=a[i].a2;
				 } 
				for(long long i=n/2+1;i<=n;i++)
				{
					ans+=max(a[i].a3,a[i].a1);
				}
			}
			 else if(x3>n/2)
			{
				sort(a+1,a+n+1,cmp3);
				for(long long i=1;i<=n/2;i++)
				{
					ans+=a[i].a3;
				 } 
				for(long long i=n/2+1;i<=n;i++)
				{
					ans+=max(a[i].a1,a[i].a2);
				}
			}
			
			
			
			
			else{
				for(long long i=1;i<=n;i++)
				{
					ans+=a[i].da;
				 } 
			}
		}
		cout<<ceil(ans/4)<<endl;
	}
 }
	return 0;
}
