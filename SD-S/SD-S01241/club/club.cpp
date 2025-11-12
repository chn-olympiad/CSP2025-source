#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x,i) cerr<<#x<<"="<<x<<" \n"[i]

const int MAX=1e5+10;

struct node
{
	int a,b,c;
	int delta;
	int op;
};

node a[MAX];
node wait[MAX];
int cnt[10];
int tmp[10];

int sol(int i)
{
	if(a[i].op==1)
	{
		return a[i].a;
	}
	else if(a[i].op==2)
	{
		return a[i].b;
	}
	else
	{
		return a[i].c;
	}
}

bool cmp(int x,int y)
{
	return x>y;
}

bool cmp1(node x,node y)
{
	return x.delta>y.delta;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		
		for(int i=1;i<=5;i++)
		{
			cnt[i]=0;
		}
		
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i]={x,y,z,0,0};
			if(x>=y&&x>=z)
			{
				cnt[1]++;
				a[i].op=1;
			}
			else if(y>=x&&y>=z)
			{
				cnt[2]++;
				a[i].op=2;
			}
			else if(z>=x&&z>=y)
			{
				cnt[3]++;
				a[i].op=3;
			}
		}
		
		int ans=0;
		int opt;
		if(cnt[1]>n/2)
		{
			opt=1;
		}
		else if(cnt[2]>n/2)
		{
			opt=2;
		}
		else if(cnt[3]>n/2)
		{
			opt=3;
		}
		
		
		
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].op!=opt)
			{
				ans=ans+sol(i);
			}
			else
			{
				wait[++tot]=a[i];
			}
		}
		
	//	debug(tot,1);
	//	debug(ans,1);
	//	
	//	debug(opt,1);
		for(int i=1;i<=tot;i++)
		{
			tmp[1]=wait[i].a;
			tmp[2]=wait[i].b;
			tmp[3]=wait[i].c;
			
			sort(tmp+1,tmp+4,cmp);
			
			wait[i].a=tmp[1];
			wait[i].b=tmp[2];
			wait[i].c=tmp[3];
			wait[i].delta=wait[i].a-wait[i].b;
		}
		
		sort(wait+1,wait+tot+1,cmp1);
		
	//	for(int i=1;i<=tot;i++)
	//	{
	//		cout<<wait[i].a<<" "<<wait[i].b<<" "<<wait[i].c<<endl;
	//	}
		
		for(int i=1;i<=tot;i++)
		{
			if(i<=n/2)
			{
				ans=ans+wait[i].a;
			}
			else
			{
				ans=ans+wait[i].b;
			}	
		}
		
		cout<<ans<<endl;
	}
	
	
	return 0;
 }

