#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
	int id,line,minn;
	bool pan=false;
};

bool cmp(node a,node b)
{
	return a.minn<b.minn;
}

const int N=1e5+5;
int t,n,lin,c[5],d[N],a[N][5]; 
node ss[N];

void solve()
{
	cin>>n;
	lin=(n>>1);
	int s1,s2,s3,sum;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)	cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(a[i][j]>a[i][d[i]])	d[i]=j; 
		}
	}
	s1=s2=s3=sum=0;
	for(int i=1;i<=n;i++)
	{
		s1+=(d[i]==1);
		s2+=(d[i]==2);
		s3+=(d[i]==3);
		sum+=a[i][d[i]];
	}
	if(s1<=lin&&s2<=lin&&s3<=lin)
	{
		cout<<sum<<"\n";
		return;
	}
	int cc=0;
	if(s1>lin)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==1)
			{
				ss[++cc].line=i;
				if(a[i][1]-a[i][2]<a[i][1]-a[i][3])
				{
					ss[cc].id=2;
					ss[cc].minn=a[i][1]-a[i][2];
				}
				if(a[i][1]-a[i][2]>a[i][1]-a[i][3])
				{
					ss[cc].id=3;
					ss[cc].minn=a[i][1]-a[i][3];
				}
				if(a[i][1]-a[i][2]==a[i][1]-a[i][3])
				{
					ss[cc].pan=true;
					ss[cc].minn=a[i][1]-a[i][2];
				}
			}
		}
		stack<int> sta;
		int ii=1,cun=0;
		sort(ss+1,ss+cc+1,cmp);
		while(s1>lin)
		{
			if(s1-lin==cun)
			{
				while(!sta.empty())
				{
					ii=sta.top();
					sum-=ss[ii].minn;
					sta.pop();
					s1--;
				}
			}
			if(ss[ii].id==2&&s2<lin)
			{
				s2++,s1--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].id==3&&s3<lin)
			{
				s3++,s1--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].pan==true)
			{
				cun++;
				sta.push(ii);
			}
			ii++;
		}
		cout<<sum<<"\n";
		return;
	}
	if(s2>lin)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==2)
			{
				ss[++cc].line=i;
				if(a[i][2]-a[i][1]<a[i][2]-a[i][3])
				{
					ss[cc].id=1;
					ss[cc].minn=a[i][2]-a[i][1];
				}
				if(a[i][2]-a[i][1]>a[i][2]-a[i][3])
				{
					ss[cc].id=3;
					ss[cc].minn=a[i][2]-a[i][3];
				}
				if(a[i][2]-a[i][1]==a[i][2]-a[i][3])
				{
					ss[cc].pan=true;
					ss[cc].minn=a[i][2]-a[i][1];
				}
			}
		}
		stack<int> sta;
		int ii=1,cun=0;
		sort(ss+1,ss+cc+1,cmp);
		while(s2>lin)
		{
			if(s2-lin==cun)
			{
				while(!sta.empty())
				{
					ii=sta.top();
					sum-=ss[ii].minn;
					sta.pop();
					s2--;
				}
			}
			if(ss[ii].id==1&&s1<lin)
			{
				s1++,s2--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].id==3&&s3<lin)
			{
				s3++,s2--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].pan==true)
			{
				cun++;
				sta.push(ii);
			}
			ii++;
		}
		cout<<sum<<"\n";
		return;
	}
	if(s3>lin)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]==3)
			{
				ss[++cc].line=i;
				if(a[i][3]-a[i][1]<a[i][3]-a[i][2])
				{
					ss[cc].id=1;
					ss[cc].minn=a[i][3]-a[i][1];
				}
				if(a[i][3]-a[i][1]>a[i][3]-a[i][2])
				{
					ss[cc].id=2;
					ss[cc].minn=a[i][3]-a[i][2];
				}
				if(a[i][3]-a[i][1]==a[i][3]-a[i][2])
				{
					ss[cc].pan=true;
					ss[cc].minn=a[i][3]-a[i][2];
				}
			}
		}
		stack<int> sta;
		int ii=1,cun=0;
		sort(ss+1,ss+cc+1,cmp);
		while(s3>lin)
		{
			if(s3-lin==cun)
			{
				while(!sta.empty())
				{
					ii=sta.top();
					sum-=ss[ii].minn;
					sta.pop();
					s3--;
				}
			}
			if(ss[ii].id==1&&s1<lin)
			{
				s1++,s3--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].id==2&&s2<lin)
			{
				s2++,s3--;
				sum-=ss[ii].minn;
			}
			if(ss[ii].pan==true)
			{
				cun++;
				sta.push(ii);
			}
			ii++;
		}
		cout<<sum<<"\n";
		return;
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)	solve();
	return 0;
}
