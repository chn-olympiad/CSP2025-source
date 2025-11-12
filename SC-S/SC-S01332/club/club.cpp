#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,s[N][5],ans,cnt,t1,t2,t3,ss0,ss1,ss2,ss3;
bool flag1,flag[N];
struct st
{
	int d1,d2,d3,id;
}a[N],b[N],c[N];
bool cmp1(st x,st y)
{
	return x.d1>y.d1;
}
bool cmp2(st x,st y)
{
	return x.d2>y.d2;
}
bool cmp3(st x,st y)
{
	return x.d3>y.d3;
}
void dfs(int id,int sum,int s1,int s2,int s3)
{
	if(cnt>=5e6)	return;
	cnt++;
	if(s1>n/2||s2>n/2||s3>n/2)	return;
	if(id>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)	dfs(id+1,sum+s[id][i],s1+1,s2,s3);
		if(i==2)	dfs(id+1,sum+s[id][i],s1,s2+1,s3);
		if(i==3)	dfs(id+1,sum+s[id][i],s1,s2,s3+1);
	}
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=cnt=0;
		ss0=ss1=ss2=ss3=0; 
		flag1=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>s[i][j];
			}
			if(!(s[i][2]==0&&s[i][3]==0))	flag1=0;
			b[i].d1=c[i].d1=a[i].d1=s[i][1];
			b[i].d2=c[i].d2=a[i].d2=s[i][2];
			b[i].d3=c[i].d3=a[i].d3=s[i][3];
			b[i].id=c[i].id=a[i].id=i;
			t1+=s[i][1];
			t2+=s[i][2];
			t3+=s[i][3];
		}
		if(flag1)
		{
			int sum=0,as[N];
			for(int i=1;i<=n;i++)
			{
				as[i]=s[i][1];
			}
			sort(as+1,as+n+1);
			for(int i=n;i>=1;i--)
			{
				sum+=as[i];
			}
			cout<<sum;
			continue;
		}
		if(n<=15)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		else
		{
			sort(a+1,a+n+1,cmp1);
			sort(b+1,b+n+1,cmp2);
			sort(c+1,c+n+1,cmp3);
			for(int i=1;i<=n;i++)
			{
				if(ss0==n)	break;
				if(a[i].id==b[i].id&&(!(c[i].d3>a[i].d1&&c[i].d3>b[i].d2)))
				{
					if(ss2==n/2)
					{
						ans+=a[i].d1;
						ss1++;
					}
					if(ss1==n/2)
					{
						ans+=b[i].d2;
						ss2++;
					}
					if((a[i].d1>b[i].d2)||((a[i].d1==b[i].d2)&&(t1<t2)))
					{
						ans+=a[i].d1;
						ss1++;
					}
					else
					{
						ans+=b[i].d2;
						ss2++;
					}
					flag[a[i].id]=1;
				}
				else if(a[i].id==c[i].id&&(!(b[i].d2>a[i].d1&&b[i].d2>c[i].d3)))
				{
					if(ss3==n/2)
					{
						ans+=a[i].d1;
						ss1++;
					}
					if(ss1==n/2)
					{
						ans+=c[i].d3;
						ss3++;
					}
					if((a[i].d1>c[i].d3)||((a[i].d1==c[i].d3)&&(t1<t3)))
					{
						ans+=a[i].d1;
						ss1++;
					}
					else
					{
						ans+=c[i].d3;
						ss3++;
					}
					flag[a[i].id]=1;
				}
				else if(b[i].id==c[i].id&&(!(a[i].d1>b[i].d2&&a[i].d1>c[i].d3)))
				{
					if(ss3==n/2)
					{
						ans+=b[i].d2;
						ss1++;
					}
					if(ss2==n/2)
					{
						ans+=c[i].d3;
						ss3++;
					}
					if((b[i].d2>c[i].d3)||((b[i].d2==c[i].d3)&&(t2<t3)))
					{
						ans+=b[i].d2;
						ss2++;
					}
					else
					{
						ans+=c[i].d3;
						ss3++;
					}
					flag[b[i].id]=1;
				}
				else
				{
					if(ss1<n/2&&flag[a[i].id]==0)
					{
						ans+=a[i].d1;
						ss1++;
						flag[a[i].id]=1;
					}
					if(ss2<n/2&&flag[b[i].id]==0)
					{
						ans+=b[i].d2;
						ss2++;
						flag[b[i].id]=1;
					}
					if(ss3<n/2&&flag[c[i].id]==0)
					{
						ans+=c[i].d3;
						ss3++;
						flag[a[i].id]=1;
					}
				}
				ss0=ss1+ss2+ss3;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
