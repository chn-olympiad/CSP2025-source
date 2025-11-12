#include<bits/stdc++.h>
using namespace std;
int n,k,ans,cnt;
int a[100050],f[1005][1005];
bool vis[1005][1005];
struct node
{
	int x,y;
};
node p[100050];
bool low(int sta,int fia,int stb,int fib)
{
	if ((sta>=stb&&sta<=fib)||(fia>=stb&&fia<=fib)) return true;
	return false;
}
int bfs()
{
	memset(vis,false,sizeof(vis));
	int q[1005][5];
	int head=1,tail=1;
	q[head][0]=p[1].x;
	q[head][1]=p[1].y;
	q[head][2]=1;
	int lst=p[1].x,let=p[1].y;
	while (head<=tail)
	{
		for (int i=2;i<=cnt;i++)
		{
			if (!low(p[i].x,p[i].y,lst,let)) 
			{
				lst=min(lst,p[i].x);
				let=max(let,p[i].y);
				q[++tail][0]=p[i].x;
				q[tail][1]=p[i].y;
				q[tail][2]=q[tail-1][2]+1;
			}
		}
		head++;
	}
	return q[tail][2];
}
int main()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	bool fl=true;
	int jsq=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (fl==true&&a[i]==1) jsq++;
		if (a[i]>1) fl=false;
	}
	if (fl==true&&k==1)
	{
		cout<<jsq;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		f[i][i]=a[i];
		for (int j=i+1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^a[j];
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (f[i][j]==k) p[++cnt].x=i,p[cnt].y=j;
	ans=bfs();
	cout<<ans;
	return 0;
}