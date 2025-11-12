#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define pb push_back
const int maxn=100005;
using namespace std;
struct pii {int fr,se;};
bool operator < (pii a,pii b) {return a.fr==b.fr?a.fr<b.fr:a.se<b.se;}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
int a[maxn][4],ch[maxn],siz[3];
priority_queue<int>q;
void mian()
{
	siz[0]=siz[1]=siz[2]=0;
	n=read();
	while (q.size()) q.pop();
	for (int i=1;i<=n;i++)
	{
		a[i][0]=read();a[i][1]=read();a[i][2]=read();
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ch[i]=(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]?0:1+(a[i][2]>a[i][1]));
		siz[ch[i]]++;ans+=a[i][ch[i]];
		a[i][3]=a[i][ch[i]];a[i][ch[i]]=0;
//		for (int j=0;j<4;j++) cout<<a[i][j]<<" ";cout<<endl;
	}
	int p=(siz[0]>=siz[1]&&siz[0]>=siz[2]?0:1+(siz[2]>siz[1]));
	if (siz[p]>n/2)
	{
		for (int i=1;i<=n;i++) if (ch[i]==p)
		{
			int v=max(a[i][0],max(a[i][1],a[i][2]));
//			cout<<i<<":"<<v-a[i][3]<<endl;
			q.push(v-a[i][3]);
		}
		while (siz[p]!=n/2)
		{
			ans+=q.top();q.pop();
			siz[p]--;
		}
	}
	write(ans);putchar('\n');
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while (T--) mian();
	return 0;
}
/*
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
