#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
int T,n,a[100010][4],ans=0;
vector<int> ve[4];
struct node
{
	int cha,id;
}b[100010];
inline bool cmp(node x,node y)
{
	return x.cha>y.cha;
}
inline void solve(int k)
{
	int cnt=0;
	for(int i:ve[k])
	{
		int ma=-1;
		if(k==1)
		{
			ma=max(a[i][2],a[i][3]);
		}
		if(k==2)
		{
			ma=max(a[i][1],a[i][3]);
		}
		if(k==3)
		{
			ma=max(a[i][1],a[i][2]);
		}
		cnt++;
		b[cnt]={a[i][k]-ma,i};
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans=ans+a[b[i].id][k];
	}
	for(int i=n/2+1;i<=cnt;i++)
	{
		int I=b[i].id,ma=-1;
		if(k==1)
		{
			ma=max(a[I][2],a[I][3]);
		}
		if(k==2)
		{
			ma=max(a[I][1],a[I][3]);
		}
		if(k==3)
		{
			ma=max(a[I][1],a[I][2]);
		}
		ans=ans+ma;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		ans=0;
		n=read();
		ve[1].clear();
		ve[2].clear();
		ve[3].clear();
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			int Maxi=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]==Maxi)
			{
				ve[1].push_back(i);
			}
			else if(a[i][2]==Maxi)
			{
				ve[2].push_back(i);
			}
			else
			{
				ve[3].push_back(i);
			}
		}
		int k1=(int)ve[1].size(),k2=(int)ve[2].size(),k3=(int)ve[3].size();
		if(k1*2<=n&&k2*2<=n&&k3*2<=n)
		{
			for(int i:ve[1])ans=ans+a[i][1];
			for(int i:ve[2])ans=ans+a[i][2];
			for(int i:ve[3])ans=ans+a[i][3];
			print(ans);
			puts("");
			continue;
		}
		if(k1*2<=n)for(int i:ve[1])ans=ans+a[i][1];
		else solve(1);
		if(k2*2<=n)for(int i:ve[2])ans=ans+a[i][2];
		else solve(2);
		if(k3*2<=n)for(int i:ve[3])ans=ans+a[i][3];
		else solve(3);
		print(ans);
		puts("");
	}
}
