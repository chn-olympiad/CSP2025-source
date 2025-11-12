#include<bits/stdc++.h>
using namespace std;
long long n,T,sum;
long long a[100010],b[10010],c[10010],a_sum,b_sum,c_sum;
struct club
{
	int a,b,c;
	char ma;
	bool judge;
}arr[100010];
bool cmp(club a1,club a2)
{
	if(a1.a!=a2.a) return a1.a>a2.a;
	else if(a1.b!=a2.b) return a1.b>a2.b;
	else return a1.c>a2.c;
}
int main()
{                                          
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(arr,0,sizeof(arr));
		sum=0;
		a_sum=0;
		b_sum=0;
		c_sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			int maxx=max(max(arr[i].a,arr[i].b),arr[i].c);
			if(maxx==arr[i].a) arr[i].ma='a';
			else if(maxx==arr[i].b) arr[i].ma='b';
			else arr[i].ma='c';
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(arr[i].a==0&&arr[i].b==0)
			{
				if(c_sum<n/2)
				{
					sum+=arr[i].c;
					c_sum++;
					arr[i].judge=1;	
				}
			}
			else if(arr[i].a==0&&arr[i].c==0)
			{
				if(b_sum<n/2)
				{
					sum+=arr[i].b;
					b_sum++;
					arr[i].judge=1;	
				}
			}
			else if(arr[i].c==0&&arr[i].b==0)
			{
				if(c_sum<n/2)
				{
					sum+=arr[i].a;
					a_sum++;
					arr[i].judge=1;	
				}	
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(arr[i].judge==1) continue;
			if(arr[i].ma=='a') 
			{
				if(a_sum<n/2)
				{
					sum+=arr[i].a;
					a_sum++;
				}
				else if(arr[i].b>arr[i].c)
				{
					if(b_sum<n/2)
					{
						sum+=arr[i].b;
						b_sum++;				
					}
					else 
					{
						sum+=arr[i].c;
						c_sum++;
					}
				}
			}
			else if(arr[i].ma=='b')
			{
				if(b_sum<n/2)
				{
					sum+=arr[i].b;
					b_sum++;	
				}
				else if(arr[i].a>arr[i].c)
				{
					if(a_sum<n/2)
					{
						sum+=arr[i].b;
						a_sum++;			
					}
					else 
					{
						sum+=arr[i].c;
						c_sum++;
					}
				}
			}
			else if(arr[i].ma=='c')
			{
				if(c_sum<n/2)
				{
					sum+=arr[i].c;
					c_sum++;
				}
				else if(arr[i].a>arr[i].b)
				{
					if(a_sum<n/2)
					{
						sum+=arr[i].a;
						a_sum++;
					}
					else 
					{
						sum+=arr[i].b;
						b_sum++;
					}
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
 } 
