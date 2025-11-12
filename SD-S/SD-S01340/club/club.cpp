#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;

const int N=1e5+10;
int t,n,m,tot[5];
ll ans;
struct node{
	int one,two,three,mx,loc;
}num[N];

bool cmp(node a,node b)
{
	return a.mx>b.mx;
}

void doit_tan()
{
	int upp=n/2;
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&num[i].one,&num[i].two,&num[i].three);
		if(num[i].three) flag=1;
		if(num[i].one>=num[i].two && num[i].one>=num[i].three)
		{
			num[i].mx=num[i].one;
			num[i].loc=1;
		}
		else if(num[i].two>=num[i].one && num[i].two>=num[i].three)
		{
			num[i].mx=num[i].two;
			num[i].loc=2;
		}
		else if(num[i].three>=num[i].one && num[i].three>=num[i].two)
		{
			num[i].mx=num[i].three;
			num[i].loc=3;
		}
	}
	sort(num+1,num+1+n,cmp);
//_____________________________________________________

//    for(int i=1;i<=n;i++)
//    cout<<num[i].one<<" "<<num[i].two<<" "<<num[i].three<<" "<<num[i].mx<<" "<<num[i].loc<<endl;
    
//_______________________________________________________
	for(int i=1;i<=n;i++)
	{
		if(tot[num[i].loc]<upp)
		{
			tot[num[i].loc]++;
			ans+=num[i].mx;
		}
		else
		{
			if(num[i].loc==1)
			{
				if(num[i].two>=num[i].three && tot[2]<upp)
				{
					tot[2]++;
					ans+=num[i].two;
				}
				else
				{
					tot[3]++;
					ans+=num[i].three;
				}
			}
			else if(num[i].loc==2)
			{
				if(num[i].one>=num[i].three && tot[1]<upp)
				{
					tot[1]++;
					ans+=num[i].one;
				}
				else
				{
					tot[3]++;
					ans+=num[i].three;
				}
			}
			else
			{
				if(num[i].one>=num[i].two && tot[1]<upp)
				{
					tot[1]++;
					ans+=num[i].one;
				}
				else
				{
					tot[2]++;
					ans+=num[i].two;
				}
			}
		}
	}
	printf("%lld\n",ans);
}

void dfs(int u,ll cnt,int upp,int on,int tw,int th)
{
	if(on>upp || tw>upp || th>upp) return;
	if(u==n+1)
	{
		ans=max(ans,cnt);
		return;
	}
	
	if(on<upp && tw<upp && th<upp)
	{
		dfs(u+1,cnt+num[u].one,upp,on+1,tw,th);
	    dfs(u+1,cnt+num[u].two,upp,on,tw+1,th);
	    dfs(u+1,cnt+num[u].three,upp,on,tw,th+1);
	}
	else if(on==upp)
	{
		int mxx=max(num[u].two,num[u].three);
		dfs(u+1,cnt+mxx,upp,on,tw,th);
	}
	else if(tw==upp)
	{
		int mxx=max(num[u].one,num[u].three);
		dfs(u+1,cnt+mxx,upp,on,tw,th);
	}
	else if(th==upp)
	{
		int mxx=max(num[u].two,num[u].one);
		dfs(u+1,cnt+mxx,upp,on,tw,th);
	}
}

void doit40()
{
	int upp=n/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&num[i].one,&num[i].two,&num[i].three);
	}
	dfs(1,0,upp,0,0,0);
	printf("%lld\n",ans);
}

void solve()
{
	scanf("%d",&n);
	if(n<=30) doit40();
	else doit_tan();
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(tot,0,sizeof(tot));
	    ans=0;
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


















//_________________________________________________________

