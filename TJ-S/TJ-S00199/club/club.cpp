#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005][4];
int x1,x2,x3;
int ans=0;
struct Node
{
	int ma,id;
}b[100005];
bool used[100005];
bool cmp(Node x,Node y)
{
	if(x.ma==y.ma) return x.id<y.id;
	return x.ma>y.ma;
}
bool tw_is_0()
{
	for(int i=1;i<=n;i++) if(a[i][2]!=0) return false;
	return true;
}
bool th_is_0()
{
	for(int i=1;i<=n;i++) if(a[i][3]!=0) return false;
	return true;
}
void dfs(int k,int val)
{
	if(k==n+1)
	{
		if(x1<=n/2&&x2<=n/2&&x3<=n/2)
		{
			ans=max(ans,val);
		}
		return;
	}
	
	x1++;
	dfs(k+1,val+a[k][1]);
	x1--;
	
	x2++;
	dfs(k+1,val+a[k][2]);
	x2--;
	
	x3++;
	dfs(k+1,val+a[k][3]);
	x3--;
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i].ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]) b[i].id=1;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]) b[i].id=2;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]) b[i].id=3;
		}
		
		ans=0;
		if(n<=18)
		{
			x1=0; x2=0; x3=0;
			dfs(1,0);
			cout<<ans<<endl;
		}
		else if(th_is_0())
		{
			sort(b+1,b+1+n,cmp);
			int ans=0;
			if(tw_is_0()) 
			{
				for(int i=1;i<=n/2;i++) ans+=b[i].ma;
			}
			else
			{
				int jsq1=0,jsq2=0;
				for(int i=1;i<=n;i++) 
				{
					if(b[i].id==1) jsq1++;
					else jsq2++;
				}
				if(jsq1>jsq2)
				{
					for(int i=1,x=0;i<=n,x<=n/2;i++)
					{
						if(b[i].id==1) ans+=b[i].ma;
						used[i]=1;
						x++;
					}
					for(int i=1;i<=n;i++)
						if(!used[i]) ans+=b[i].ma;
				}
				if(jsq1<jsq2)
				{
					for(int i=1,x=0;i<=n,x<=n/2;i++)
					{
						if(b[i].id==2) ans+=b[i].ma;
						used[i]=1;
						x++;
					}
					for(int i=1;i<=n;i++)
						if(!used[i]) ans+=b[i].ma;
				}
				if(jsq1==jsq2)
				{
					for(int i=1;i<=n;i++) ans+=b[i].ma;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
