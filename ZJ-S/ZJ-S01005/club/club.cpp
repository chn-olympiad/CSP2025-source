#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char ch=getchar();
	int c=0,d=1;
	while(!isdigit(ch))
	{
		if(ch=='-')d=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		c=c*10+(ch-'0');
		ch=getchar();
	}
	return c*d;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return ;
	}
	if(x>=10)write(x/10);
	putchar(char(x%10+'0'));
	return ;
}
const int N=100005;
int n,ans,T;
struct node
{
	int a,b,c;
}cl[N];
bool cmp(node x,node y)
{
	return max(x.b,x.c)>max(y.b,y.c);
}
void solve1()
{
	ans=0;
	
	for(int i=1;i<=n;i++)
	  cl[i].a=read(),cl[i].b=read(),cl[i].c=read(),cl[i].b-=cl[i].a,cl[i].c-=cl[i].a,ans+=cl[i].a;
	int cnt1=0,cnt2=0,cnt3=0;
	sort(cl+1,cl+n+1,cmp);
//	for(int i=1;i<=n;i++)
//	  cout<<cl[i].b<<' '<<cl[i].c<<endl;
	for(int i=1;i<=n/2;i++)
	  if(cl[i].b>cl[i].c)
	  {
	  	cnt1++;
	  	ans+=cl[i].b;
	  }
	  else if(cl[i].b<cl[i].c)
	  {
	  	cnt2++;
	  	ans+=cl[i].c;
	  }
	  else ans+=cl[i].c,cnt3++;
	for(int i=n/2+1;i<=n;i++)
	{
		if(max(cl[i].b,cl[i].c)<=0)
		{
			cout<<ans<<endl;
			return ;
		}
		//cnt1+cnt2+cnt3
		if(cl[i].b>cl[i].c)
		{
			if(cnt1<n/2)cnt1++,ans+=cl[i].b;
			else if(cl[i].c>0&&cnt2<n/2)cnt2++,ans+=cl[i].c;
		}
		else if(cl[i].b<cl[i].c)
		{
			if(cnt2<n/2)cnt2++,ans+=cl[i].c;
			else if(cl[i].b>0&&cnt1<n/2)cnt1++,ans+=cl[i].b;
		}
		else cnt3++,ans+=cl[i].b;
	}
	cout<<ans<<endl;
	return ;
}
int f[201][201][201];
void solve2()
{
	for(int i=1;i<=n;i++)cl[i].a=read(),cl[i].b=read(),cl[i].c=read();
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=min(i,n/2);j++)
	    for(int k=0;k<=min(i,n/2);k++)
	    {
	    	f[i][j][k]=0;
	    	if(i-j-k<=n/2)f[i][j][k]=f[i-1][j][k]+cl[i].a;
	    	if(j!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+cl[i].b);
	    	if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+cl[i].c);
		}
	int ans=0;
//	cout<<f[10][5][4]<<endl;
	for(int i=0;i<=n/2;i++)
	  for(int j=0;j<=n/2;j++)
	    if(n-i-j<=n/2)ans=max(ans,f[n][i][j]);
	cout<<ans<<endl;
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		if(n>200)solve1();
		else solve2();
	}
}
