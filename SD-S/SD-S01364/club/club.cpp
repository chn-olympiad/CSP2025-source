#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int st1,st2,st3;
int del1[100005],del2[100005],del3[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans=0;
		int topp=n/2;
		int best=0;
		int p1=0,p2=0,p3=0;
		long long sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>st1>>st2>>st3;
			int max_=max(max(st1,st2),st3);
			best=0;
			if(st1==max_)
			{
				best+=1;
			}
			if(st2==max_)
			{
				best+=10;
			}
			if(st3==max_)
			{
				best+=100;
			}
			if(best==1)
			{
				p1++;
				del1[p1]=st1-max(st2,st3);
				sum1+=st1;
				continue;
			}
			if(best==10)
			{
				p2++;
				del2[p2]=st2-max(st1,st3);
				sum2+=st2;
				continue;
			}
			if(best==100)
			{
				p3++;
				del3[p3]=st3-max(st1,st2);
				sum3+=st3;
				continue;
			}
			ans+=max_;
		}
		ans+=(sum1+sum2+sum3);
		if(p1>topp)
		{
			sort(del1+1,del1+1+p1);
			for(int i=1;i<=p1-topp;i++)
			{
				ans-=del1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(p2>topp)
		{
			sort(del2+1,del2+1+p2);
			for(int i=1;i<=p2-topp;i++)
			{
				ans-=del2[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(p3>topp)
		{
			sort(del3+1,del3+1+p3);
			for(int i=1;i<=p3-topp;i++)
			{
				ans-=del3[i];
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
