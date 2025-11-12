//722094
#include<bits/stdc++.h>

using namespace std;
#define int long long 

const int N=1e6+15;

int read()
{
	int x=0,f=1;
	char ch=getchar();
	if(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
			ch=getchar();
		}
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

struct node
{
	int val,name,bel;
}stk[N];
bool fl[N];
int cnt[N],delta[N];
int a[N][5];
vector<int> p[5];
int top,ans;
int n,t;

bool cmp(node a,node b)
{
	return a.val>b.val;
}

bool cmpd(int x,int y)
{
	return x<y;
}

pair<int,int> get(int loc)
{
	int maxx=a[loc][1];
	int cmax=0;
	if(a[loc][2]>=maxx)
	{
		cmax=maxx;
		maxx=a[loc][2];
	}
	else if(a[loc][2]>=cmax)
		cmax=a[loc][2];
	if(a[loc][3]>=maxx)
	{
		cmax=maxx;
		maxx=a[loc][3];
	}
	else if(a[loc][3]>=cmax)
		cmax=a[loc][3];
	return {maxx,cmax};
}

void init()
{
	top=0;
	ans=0;
	p[1].clear();
	p[2].clear();
	p[3].clear();
	for(int i=0;i<=n;i++)
		fl[i]=0,cnt[i]=0,delta[i]=0;
}

void solve()
{
//	cin>>n;
	n=read();
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
//			cin>>a[i][j];
			a[i][j]=read();
			stk[++top]=(node){a[i][j],i,j};
		}
	sort(stk+1,stk+top+1,cmp);
	for(int i=1;i<=top;i++)
	{
		if(!fl[stk[i].name])
		{
			ans+=stk[i].val;
			cnt[stk[i].bel]++;
			fl[stk[i].name]=1;
			p[stk[i].bel].push_back(stk[i].name);
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>n/2)
		{
			for(int j=0;j<cnt[i];j++)
			{
				int loc=p[i][j];
//				cout<<loc<<" ";
				int maxx=get(loc).first;
				int cmax=get(loc).second;
				delta[j]=maxx-cmax;
			}
//			cout<<endl;
			sort(delta,delta+cnt[i],cmpd);
//			cout<<"case "<<i<<endl;
//			for(int j=0;j<cnt[i];j++)
//				cout<<delta[j]<<" ";
//			cout<<endl;
			int now=0;
			while(cnt[i]>n/2)
			{
				ans-=delta[now];
				cnt[i]--;
				now++;
			}
		}
	}
	cout<<ans<<endl;
	return;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cin>>t;
	t=read();
	while(t--)
		solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/