#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[5];
long long ans=0;
struct stu{
	int a1,a2,a3,id,dx;
	void read(){
		
		scanf("%d%d%d",&a1,&a2,&a3);
		if(a1>=a2&&a1>=a3)
		{
			id=1,num[1]++;
			dx=a1-max(a2,a3);
			ans+=a1;
		}
		else if(a2>=a1&&a2>=a3)
		{
			id=2,num[2]++;
			dx=a2-max(a1,a3);
			ans+=a2;
		}
		else
		{
			id=3,num[3]++;
			dx=a3-max(a1,a2);
			ans+=a3;
		}
	}
}a[100005],b[100005];
bool cmp(stu x,stu y)
{
	return x.dx>y.dx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=3;i++)
		{
			num[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			a[i].read();
			
		}
		int cur=0;
		if(num[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].id==1)
				{
					b[++cur]=a[i];
				}
			}
			sort(b+1,b+cur+1,cmp);
			for(int i=num[1];i>n/2;i--)
			{
				ans-=b[i].dx;
			}
		}
		else if(num[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].id==2)
				{
					b[++cur]=a[i];
				}
			}
			sort(b+1,b+cur+1,cmp);
			for(int i=num[2];i>n/2;i--)
			{
				ans-=b[i].dx;
			}
		}
		else if(num[3]>n/2){
			for(int i=1;i<=n;i++)
			{
				if(a[i].id==3)
				{
					b[++cur]=a[i];
				}
			}
			sort(b+1,b+cur+1,cmp);
			for(int i=num[3];i>n/2;i--)
			{
				ans-=b[i].dx;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}