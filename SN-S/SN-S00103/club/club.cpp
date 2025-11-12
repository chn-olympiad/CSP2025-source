#include<bits/stdc++.h>
using namespace std;
int n,t;
int A=1,B=1;
long long ans[5];
long long maxn[100010];
int cnt1,cnt2,cnt3;
long long ans_=0;
struct stu
{
	int a1,a2,a3;
}a[100010];
bool cmp1(stu x,stu y)
{
	return x.a1>y.a1; 
}
bool cmp2(stu x,stu y)
{
	return x.a2>y.a2; 
}
bool cmp3(stu x,stu y)
{
	return x.a3>y.a3; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	for(int r=0;r<t;r++)
	{
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			maxn[i]=max(max(a[i].a1,a[i].a2),a[i].a3);
			if(a[i].a2!=0||a[i].a3!=0)
				A=0;
			if(a[i].a3!=0)
				B=0;
		}
		if(A)
		{
			sort(maxn+1,maxn+n+1);
			for(int i=n;i>n/2;i--)
			{
				ans_+=maxn[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int k=1;k<=3;k++)
		{
			cnt1=0;cnt2=0;cnt3=0;
			if(k==1)
				sort(a+1,a+n+1,cmp1);
			if(k==2)
				sort(a+1,a+n+1,cmp2);
			if(k==3)
				sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n;i++)
			{
				if(a[i].a1>=a[i].a2&&a[i].a2>=a[i].a3)
				{
					//cout<<"123"<<endl; 
					if(cnt1<n/2)
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
					else if(cnt2<n/2)
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
					else
					{
						cnt3++;
						ans[k]+=a[i].a3;
					}
				}
				if(a[i].a1>=a[i].a3&&a[i].a3>a[i].a2)
				{
					//cout<<"132"<<endl;
					if(cnt1<n/2)
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
					else if(cnt3<n/2)
					{
						cnt3++;
						ans[k]+=a[i].a3;
					}
					else
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
				}
				if(a[i].a2>=a[i].a1&&a[i].a1>=a[i].a3)
				{
					
					if(cnt2<n/2)
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
					else if(cnt1<n/2)
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
					else
					{
						cnt3++;
						ans[k]+=a[i].a3;
					}//cout<<"213"<<endl;
				}
				if(a[i].a2>=a[i].a3&&a[i].a3>a[i].a1)
				{
					//cout<<"231"<<endl;
					if(cnt2<n/2)
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
					else if(cnt3<n/2)
					{
						cnt3++;
						ans[k]+=a[i].a3;
					}
					else
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
				}
				if(a[i].a3>=a[i].a2&&a[i].a2>=a[i].a1)
				{
					//cout<<"321"<<endl;
					if(cnt3<n/2)
					{
						cnt3++;
						ans[k]+=a[i].a3;
					}
					else if(cnt2<n/2)
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
					else
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
				}
				if(a[i].a3>=a[i].a1&&a[i].a1>a[i].a2)
				{
					//cout<<"312"<<endl;
					if(cnt3<n/2)
					{	
						cnt3++;
						ans[k]+=a[i].a3;
					}
					else if(cnt1<n/2)
					{
						cnt1++;
						ans[k]+=a[i].a1;
					}
					else
					{
						cnt2++;
						ans[k]+=a[i].a2;
					}
				}
			}
		}
		printf("%lld\n",max(max(ans[1],ans[2]),ans[3]));
	}
	return 0;
 }        
