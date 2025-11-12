//freopen!!!


#include<bits/stdc++.h>
#define ll long long
#define forr(a,b,c) for(int a=b;a<=c;a++)
using namespace std;

const int N=1e5+10;
const int inf=0x3f3f3f3f;
int t;
int n;
int a[N][5];
int d[N];
int f[5];
int cnt=0;

struct node{
	int id;
	int ans;
}dif[N];

void init()
{
	cnt=0;
	forr(i,1,3) f[i]=0;
}

int findd(int a,int b,int c)
{
	int minn=inf;
	minn=min(c,min(a,b));
	
	int ans;
	if(minn==a) ans=abs(b-c);
	else
	{
		if(minn==b) ans=abs(a-c);
		else ans=abs(a-b);
	}
	return ans;
}

bool cmp(node x,node y)
{
	return x.ans<y.ans;
}

void gai(int x)
{
	int shu=f[x];
	int mid=n>>1;
	sort(dif+1,dif+n+1,cmp);
	forr(i,1,n)
	{
		if(shu==mid) break;
		if(d[dif[i].id]==x)
		{
			cnt-=dif[i].ans;
			shu--;
		}
	}
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		init();
		forr(i,1,n) 
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			dif[i].ans=findd(a[i][1],a[i][2],a[i][3]);
			dif[i].id=i;
			int maxx=-1,num;
			forr(j,1,3)
				if(a[i][j]>maxx) maxx=a[i][j],num=j;
			cnt+=maxx;
			f[num]++;
			d[i]=num;
		}
		int mid=n>>1;
		forr(i,1,3)
			if(f[i]>mid) gai(i); 
		printf("%d\n",cnt);
	}
	return 0;
}

