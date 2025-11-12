#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct node{
	int z1,z2,z3,num;
}a[100005];
int p[100005];
long long f[205][205][205];
long long ans;
long long cnt1,cnt2,cnt3;
long long sum1,sum2,sum3;
bool flagA=true;
void dfs(int step)
{
	if(step>n)
	{
		long long res=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==1) res+=a[i].z1;
			if(p[i]==2) res+=a[i].z2;
			if(p[i]==3) res+=a[i].z3;
		}
		ans=max(ans,res);
		return;
	}
	if(cnt1<n/2)
	{
		cnt1++;
		p[step]=1;
		dfs(step+1);
		cnt1--;
	}
	if(cnt2<n/2)
	{
		cnt2++;
		p[step]=2;
		dfs(step+1);
		cnt2--;
	}
	if(cnt3<n/2)
	{
		cnt3++;
		p[step]=3;
		dfs(step+1);
		cnt3--;
	}
}
bool cmp1(node kk1,node kk2)
{
	return kk1.z1>kk2.z1;
}
bool cmp2(node kk1,node kk2)
{
	return kk1.z2>kk2.z2;
}
bool cmp3(node kk1,node kk2)
{
	return kk1.z3>kk2.z3;
}
bool cmp4(node kk1,node kk2)
{
	return kk1.num<kk2.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cnt1=cnt2=cnt3=0;
		flagA=true;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].z1>>a[i].z2>>a[i].z3;
			sum1+=a[i].z1;
			sum2+=a[i].z2;
			sum3+=a[i].z3;
			a[i].num=i;
			if(a[i].z2!=0 || a[i].z3!=0)
			{
				flagA=false;
			}
		}
		if(n<=10)
		{
			dfs(1);
			cout<<ans<<endl;
		}
		else if(flagA)
		{
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].z1;
			}
			cout<<ans<<endl;
		}
		else if(n<=200)
		{
			for(int i=0;i<=200;i++)
			{
				for(int j=0;j<=200;j++)
				{
					for(int k=0;k<=200;k++)
					{
						f[i][j][k]=0;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						int l=i-j-k;
						if(j+k>i) continue;
						if(l>n/2) continue;
						if(j!=0) 
						{
							f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[i].z1);
						}
						if(k!=0) 
						{
							f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i].z2);
						}
						if(l!=0) 
						{
							f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i].z3);
						}
					}
				}
			}
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					ans=max(ans,f[j][k][n-j-k]);
				}
			}
			cout<<ans<<endl;
		}
	}
}

