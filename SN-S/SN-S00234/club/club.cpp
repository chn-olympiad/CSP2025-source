#include<iostream>
#include<algorithm>
using namespace std;
long long n,t,ans;
struct p
{
	long long a1,a2,a3;
	long long k;//学生编号 
	bool op1,op2,op3;//此学生是否加入部门 123
}a[100010];
long long fop,sop,top;//三个部门有的人数 
bool cmp(p x,p y)
{
	return x.a1<y.a1;
}
bool kmp(p x,p y)
{
	return x.a2<y.a2;
}
bool fmp(p x,p y)
{
	return x.a3<y.a3;
}
bool cmp1(p x,p y)
{
	return x.a1>y.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		fop=0,sop=0,top=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].k=i;
			
			
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				a[i].op1=1;
				fop++; 
				ans+=a[i].a1;
			 }
			if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3)
			{
				a[i].op2=1;
				sop++; 
				ans+=a[i].a2;
			 }
			if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1)
			{
				a[i].op3=1;
				top++; 
				ans+=a[i].a3;
			 }  
		}
		//特殊性质A
		
		long long tt=0,ss=0;
		for(int i=1;i<=n;i++)
		{
			tt+=a[i].a2;
			ss+=a[i].a3;
		}
		if(tt==0&&ss==0)
		{
			ans=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		
		
		//特殊性质B
		
		if(ss==0)
		{
			ans=0;
			for(int i=1;i<=n;i+=2)
			{
				ans+=max(a[i].a1+a[i+1].a2,a[i].a2+a[i+1].a1);
			}
			cout<<ans<<endl;
			continue;
		}
		
		
		
		 
		if(fop<=n/2&&sop<=n/2&&top<=n/2)
		{
			cout<<ans<<endl;
		}
		else
		{
			if(fop>n/2)
			{
				int tmp1=fop-n/2;
				fop-=tmp1;
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=tmp1;i++)
				{
					ans-=a[i].a1;
					a[a[i].k].op1=0;
				
					if(a[i].a2>=a[i].a3)
					{
						ans+=a[i].a2;
						sop++;
						a[a[i].k].op2=1;
					}
					else
					{
						if(a[i].a2<a[i].a3)
						{
							ans+=a[i].a3;
							top++;
							a[a[i].k].op3=1;
						}
					}
				}
			}
			if(sop>n/2)
			{
				int tmp2=sop-n/2;
				sop-=tmp2;
				sort(a+1,a+1+n,kmp);
				for(int i=1;i<=tmp2;i++)
				{
					ans-=a[i].a2;
					a[a[i].k].op2=0;
					top++;
					ans+=a[i].a3;
					a[a[i].k].op3=1;
				}
			}
			if(top>n/2)
			{
				int tmp3=top-n/2;
				top-=tmp3;
				sort(a+1,a+1+n,fmp);
				for(int i=1;i<=tmp3;i++)
				{
					ans-=a[i].a3;
					a[a[i].k].op3=0;
					sop++;
					ans+=a[i].a2;
					a[a[i].k].op3=1;
				}
			}
			
		cout<<ans<<endl;
		 } 
	
	
		
	 } 
	 return 0;
 } 
