//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int ans,n,t,x,y,z,s1,s2,s3,k;
//signed main()
//{
//	freopen("club5.in","r",stdin);
////	freopen("club.out","w",stdout);
//	cin>>t;
//	while(t--)
//	{
//		priority_queue<int,vector<int>,greater<int> > q1;
//		priority_queue<int,vector<int>,greater<int> > q2;
//		priority_queue<int,vector<int>,greater<int> > q3;
//		ans=s1=s2=s3=0;
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%lld%lld%lld",&x,&y,&z);
//			if(x>y)
//			{
//				if(x>z)
//				{
//					ans+=x;
//					s1++;
//					q1.push(x-max(y,z));
//				}
//				else
//				{
//					ans+=z;
//					s3++;
//					q3.push(z-x);
//				}
//			}
//			else
//			{
//				if(y>z)
//				{
//					ans+=y;
//					s2++;
//					q2.push(y-max(x,z));
//				}
//				else
//				{
//					ans+=z;
//					s3++;
//					q3.push(z-y);
//				}
//			}
//		}
//		if(s1>n/2)
//		{
//			k=s1-n/2;
//			while(k--)
//			{
//				ans-=q1.top();
//				q1.pop();
//			}
//		}
//		if(s2>n/2)
//		{
//			k=s2-n/2;
//			while(k--)
//			{
//				ans-=q2.top();
//				q2.pop();
//			}
//		}
//		if(s3>n/2)
//		{
//			k=s3-n/2;
//			while(k--)
//			{
//				ans-=q3.top();
//				q3.pop();
//			}
//		}
//		printf("%lld\n",ans);
//	}
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx,maxi,ans,n,t,a[100005],b[100005],c[100005],x,y,z,s1,s2,s3,k;
void dx(int k)
{
	if(x>y)
	{
		if(x>z)
		{
			ans+=x;
			s1++;
			a[s1]=x-max(y,z);	
		}
		else
		{
			ans+=z;
			s3++;
			c[s3]=z-x;
		}
	}
	else
	{
		if(y>z)
		{
			ans+=y;
			s2++;
			b[s2]=y-max(x,z);	
		}
		else
		{
			ans+=z;
			s3++;
			c[s3]=z-y;
		}
	}
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=s1=s2=s3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			dx(i);
		}
		if(s1>n/2)
		{
			sort(a+1,a+1+s1);
			k=s1-n/2;
			int i=1;
			while(k--)
			{
				ans-=a[i];
				i++;
			}
		}
		if(s2>n/2)
		{
			sort(b+1,b+1+s2);
			k=s2-n/2;
			int i=1;
			while(k--)
			{
				ans-=b[i];
				i++;
			}
		}
		if(s3>n/2)
		{
			sort(c+1,c+1+s3);
			k=s3-n/2;
			int i=1;
			while(k--)
			{
				ans-=c[i];
				i++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}