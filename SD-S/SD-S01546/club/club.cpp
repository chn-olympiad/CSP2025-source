//(p-p/i)*ni[p%i]%p
//(y,x-a/b*y) 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct point
{
	int a1,a2,a3;
}a[100005];
int t,n,a1[100005],a2[100005],a3[100005],bu[4],wow[100005];
long long sum,ans;
void dfs(int x)
{
	if(x==n+1)
	{ans=max(ans,sum);return ;}
	if(bu[1]<n/2){sum+=a[x].a1;bu[1]++;dfs(x+1);sum-=a[x].a1;bu[1]--;}
	if(bu[2]<n/2){sum+=a[x].a2;bu[2]++;dfs(x+1);sum-=a[x].a2,bu[2]--;}
	if(bu[3]<n/2){sum+=a[x].a3;bu[3]++;dfs(x+1);sum-=a[x].a3,bu[3]--;}
}
bool cmp1(point x,point y)
{
return x.a1>y.a1;
}
bool cmp2(point x,point y)
{
return x.a2>y.a2;
}
bool cmp3(point x,point y)
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
		cin>>n;
		bu[1]=bu[2]=bu[3]=0;
		bool BB=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;wow[i]=a[i].a1;
			if(a[i].a2!=0||a[i].a3!=0){BB=1;}
		}
		sum=ans=0;
		if(n<=10){dfs(1);}
		else if(!BB) 
		{
			sort(wow+1,wow+n+1);
			for(int i=n;i>n/2;i--){ans+=wow[i];}
		}
		else
		{
			sort(a+1,a+n+1,cmp1);
			wow[1]=wow[2]=wow[3]=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(wow[1]<n/2){	sum+=a[i].a1;wow[1]++;}
				else
				{			
					if(wow[2]<n/2&&(a[i].a2>a[i].a3||wow[3]>=n/2)){wow[2]++;sum+=a[i].a2;}
					else{wow[3]++;sum+=a[i].a3;}
				}
			}
			ans=max(ans,sum);
			sort(a+1,a+n+1,cmp2);
			wow[1]=wow[2]=wow[3]=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(wow[2]<n/2){	ans+=a[i].a2;wow[2]++;}
				else
				{			
					if(wow[1]<n/2&&(a[i].a1>a[i].a3||wow[1]>=n/2)){wow[1]++;sum+=a[i].a1;}
					else{wow[3]++;sum+=a[i].a3;}
				}
			}
			ans=max(sum,ans);
			sort(a+1,a+n+1,cmp3);
			wow[1]=wow[2]=wow[3]=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(wow[3]<n/2){	sum+=a[i].a3;wow[3]++;}
				else
				{			
					if(wow[2]<n/2&&(a[i].a2>a[i].a1||wow[1]>=n/2)){wow[2]++;sum+=a[i].a2;}
					else{wow[1]++;sum+=a[i].a1;}
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
