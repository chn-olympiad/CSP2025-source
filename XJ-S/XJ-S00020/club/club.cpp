#include<bits/stdc++.h>
using namespace std;
int T,n,cnt,i,j,k,cnt1,cnt2,ab[100005];
int ans;
struct node
{
	int a1,a2,a3,f=0;
}a[100005];
bool cmp1(node x,node y)
{
	if(x.a1>y.a1)
	{
		return true;
	}
	return false;
}
bool cmp2(node x,node y)
{
	if(x.a2>y.a2)
	{
		return true;
	}
	return false;
}
bool cmp3(node x,node y)
{
	if(x.a3>y.a3)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;	
	while(T--)
	{
		memset(a,0,sizeof(a));
		cnt=0;cnt1=0;cnt2=0;i=0;j=0;k=0;
		memset(ab,0,sizeof(ab));
		ans=0;
		
		cin>>n;
		for( i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			 
		}
		//////////1
		for(i=0;i<=n/2;i++)
		{
			sort(a+1,a+1+n,cmp1);
			/*for(int pp=1;pp<=n;pp++)
			{
				cout<<a[pp].a1<<" "<<a[pp].a2<<" "<<a[pp].a3<<endl;
			}*/
			for(j=1;j<=i;j++)
			{
				cnt+=a[j].a1;
				a[j].f=1;
			}
			for(int oo=1;oo<=n;oo++)
			{
				ab[oo]=a[oo].f;
			}
			cnt2=cnt;
			////////////////2
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp2);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a2;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp3);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a3;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp1);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			///////////
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp3);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a3;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp2);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a2;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp1);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			/////////////////////////
			cnt=0;
			for(int oo=1;oo<=n;oo++)
			{
				a[oo].f=0;
			}
		}
		/////////////////////2
		cnt=0;cnt1=0;cnt2=0;i=0;j=0;k=0;
		memset(ab,0,sizeof(ab));
		for(i=0;i<=n/2;i++)
		{
			sort(a+1,a+1+n,cmp2);
			/*for(int pp=1;pp<=n;pp++)
			{
				cout<<a[pp].a1<<" "<<a[pp].a2<<" "<<a[pp].a3<<endl;
			}*/
			for(j=1;j<=i;j++)
			{
				cnt+=a[j].a2;
				a[j].f=1;
			}
			for(int oo=1;oo<=n;oo++)
			{
				ab[oo]=a[oo].f;
			}
			cnt2=cnt;
			////////////////2
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp1);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a1;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp3);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a3;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp2);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			///////////
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp3);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a3;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp1);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a1;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp2);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			/////////////////////////
			cnt=0;
			for(int oo=1;oo<=n;oo++)
			{
				a[oo].f=0;
			}
		}
		////////////////////3
		cnt=0;cnt1=0;cnt2=0;i=0;j=0;k=0;
		memset(ab,0,sizeof(ab));
		for(i=0;i<=n/2;i++)
		{
			sort(a+1,a+1+n,cmp3);
			/*for(int pp=1;pp<=n;pp++)
			{
				cout<<a[pp].a1<<" "<<a[pp].a2<<" "<<a[pp].a3<<endl;
			}*/
			for(j=1;j<=i;j++)
			{
				cnt+=a[j].a3;
				a[j].f=1;
			}
			for(int oo=1;oo<=n;oo++)
			{
				ab[oo]=a[oo].f;
			}
			cnt2=cnt;
			////////////////2
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp1);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a1;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp2);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a2;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp3);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			///////////
			for(j=0;j<=n/2;j++)
			{
				
				sort(a+1,a+1+n,cmp2);
				int t=1;
				for( k=1;k<=j;k++)
				{
					while(a[t].f==1&&t<=n)
					{
						t++;
					}
					cnt+=a[t].a2;
					a[t].f=1;
				}
				sort(a+1,a+1+n,cmp1);
				k=n-i-j;
				t=1;
				for(int oo=1;oo<=min(n/2,k);oo++)
				{
					while(a[t].f==1)
					{
						t++;
					}
					cnt+=a[t].a1;
					a[t].f=1;
				}
				//cout<<cnt<<' ';
				if(cnt>ans)
				{
					ans=cnt;
				}
				cnt=cnt2;
				sort(a+1,a+1+n,cmp3);
				for(int oo=1;oo<=n;oo++)
				{
					a[oo].f=ab[oo];
				}
			}
			/////////////////////////
			cnt=0;
			for(int oo=1;oo<=n;oo++)
			{
				a[oo].f=0;
			}
		}
		/////////////////////
		
		
		
		cout<<ans<<endl;
	}
	return 0;
 } 
