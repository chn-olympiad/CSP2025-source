#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+91;

struct node{
	int id,to,num;
}data[Maxn*3];

int t,n,a[Maxn][5],ma,ca[Maxn],ans,b[Maxn];
int cnt,cntv,c[5];
bool v[Maxn],flag=0;

bool cmp(node a,node b)
{
	if(a.num!=b.num)
		return a.num>b.num;
	return ca[a.id]>ca[b.id];
}

void work()
{
	for(int i=1;i<=n;i++)
		b[i]=a[i][1];
	sort(b+1,b+1+n);
	int ret=0;
	for(int i=n;i>n/2;i--)
		ret+=b[i];
	ans=ret;
}

void tanx(int n)
{
	ans=0;
	cnt=0;
	c[1]=c[2]=c[3]=0;
	for(int i=1;i<=n;i++)
	{
		ca[i]=-1;v[i]=0;ma=-1;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			ma=max(ma,a[i][j]);
			if(!flag&&(j==2||j==3)&&a[i][j]!=0)
				flag=1;
		}
		ans+=ma;
		for(int j=1;j<=3;j++)
			data[++cnt]=(node){i,j,a[i][j]-ma};
		for(int j=1;j<=3;j++)
			ca[i]=max(ca[i],ma-a[i][j]);
	}
	if(!flag)
	{
		work();
		cout<<ans<<'\n';
	}
	else
	{
		sort(data+1,data+1+cnt,cmp);
		cntv=0;
		for(int i=1;i<=cnt&&cntv<n;i++)
			if(v[data[i].id]==0&&c[data[i].to]<n/2)
			{
				cntv++;
				v[data[i].id]=1;
				c[data[i].to]++;
				ans+=data[i].num;
			}
		cout<<ans<<"\n";
	}
	
}

void dfs(int u,int ca,int cb,int cc,int num)
{
	if(u==n)
	{
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=3;i++)
		if(i==1&&ca+1<=n/2)
			dfs(u+1,ca+1,cb,cc,num+a[u+1][i]);
		else if(i==2&&cb+1<=n/2)
			dfs(u+1,ca,cb+1,cc,num+a[u+1][i]);
		else if(i==3&&cc+1<=n/2)
			dfs(u+1,ca,cb,cc+1,num+a[u+1][i]);
	return ;
}

void baoli(int n)
{
	flag=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if((j==2||j==3)&&a[i][j]!=0)
				flag=1;	
		}
	ans=-INT_MAX;
	if(flag)
		dfs(0,0,0,0,0);
	else
		work();
	cout<<ans<<"\n";
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n>10)
			tanx(n);
		else
			baoli(n);
	}
}