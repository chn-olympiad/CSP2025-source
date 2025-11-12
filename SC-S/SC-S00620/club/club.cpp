#include<bits/stdc++.h>
using namespace std;
struct op{
	int c1,c2,c3,m1,m2,m3;
	int a,b,c;
	
}a[100050];
int t,n,flag[100050];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			flag[i]=0;
			a[i].c1=0;
			a[i].c2=0;
			a[i].c3=0;
			a[i].a=0;
			a[i].b=0;
			a[i].c=0;
			a[i].m1=0;
			a[i].m2=0;
			a[i].m3=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
			a[i].a=a[i].c1-a[i].c2;
			a[i].b=a[i].c2-a[i].c3;
			a[i].c=a[i].c3-a[i].c1;
			if(a[i].c1>=a[i].c2&&a[i].c2>=a[i].c3)
			{
				a[i].m1=1;
				a[i].m2=2;
				a[i].m3=3;
			}else if(a[i].c1>=a[i].c3&&a[i].c3>=a[i].c2)
			{
				a[i].m1=1;
				a[i].m2=3;
				a[i].m3=2;
			}else if(a[i].c2>=a[i].c1&&a[i].c1>=a[i].c3)
			{
				a[i].m1=2;
				a[i].m2=1;
				a[i].m3=3;
			}else if(a[i].c2>=a[i].c3&&a[i].c3>=a[i].c1)
			{
				a[i].m1=2;
				a[i].m2=3;
				a[i].m3=1;
			}else if(a[i].c3>=a[i].c1&&a[i].c1>=a[i].c2)
			{
				a[i].m1=3;
				a[i].m2=1;
				a[i].m3=2;
			}else if(a[i].c3>=a[i].c2&&a[i].c2>=a[i].c1)
			{
				a[i].m1=3;
				a[i].m2=2;
				a[i].m3=1;
			}
			
		}
		priority_queue<int,deque<int>,greater<int> >q1;
		priority_queue<int,deque<int>,greater<int> >q2;
		priority_queue<int,deque<int>,greater<int> >q3;
		
		
		
		for(int i=1;i<=n;i++)
		{
			if(a[i].m1==1)
			{
				q1.push(a[i].a);
			}
			if(a[i].m1==2)
			{
				q2.push(a[i].b);
			}
			if(a[i].m1==3)
			{
				q3.push(a[i].c);
			}
		}
		while(q1.size()>(n/2))
		{
			q1.pop();
		}
		int lq1=n/2-q1.size();
		while(q2.size()>(n/2))
		{
			q2.pop();
		}
		int lq2=n/2-q2.size();
		while(q3.size()>(n/2))
		{
			q3.pop();
		}
		int lq3=n/2-q3.size();
		
		for(int i=1;i<=n;i++)
		{
			if(a[i].m1==1)
			{
				if(a[i].a>=q1.top())
				{
					flag[i]=1;
				}else{
					if(a[i].m2==2&&lq2!=0)
					{
						flag[i]=2;
					}
					else{
						flag[i]=3;
					}
				}
			}
			else if(a[i].m1==3)
			{
				if(a[i].c>=q3.top())
				{
					flag[i]=3;
				}else{
					if(a[i].m2==2&&lq2!=0)
					{
						flag[i]=2;
					}
					else{
						flag[i]=1;
					}
				}
			}
			else if(a[i].m1==2)
			{
				if(a[i].b>=q2.top())
				{
					flag[i]=2;
				}else{
					if(a[i].m2==1&&lq1!=0)
					{
						flag[i]=1;
					}
					else{
						flag[i]=3;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==1)ans+=a[i].c1;
			else if(flag[i]==2)ans+=a[i].c2;
			else if(flag[i]==3)ans+=a[i].c3;
		}
			printf("%lld\n",ans);
		ans=0;
	}
	
	return 0;
}
