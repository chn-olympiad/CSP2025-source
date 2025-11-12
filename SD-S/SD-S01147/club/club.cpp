#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
int n,a[N][5],c[N][5],p[N];
struct Node
{
	int num,id;
};
Node maxx[N],nxt[N];
void qk(int x)
{
	for(int i=1;i<=x;i++)
	{
		maxx[i].num=0;
		maxx[i].id=0;
		nxt[i].num=0;
		nxt[i].id=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int abc=1;abc<=T;abc++)
	{
		cin >> n;
		int d[5]={0};
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>maxx[i].num)
				{
					nxt[i].num=maxx[i].num;
					nxt[i].id=maxx[i].id;
					maxx[i].num=a[i][j];
					maxx[i].id=j;
				}
				else
				{
					if(a[i][j]>nxt[i].num)
					{
						nxt[i].num=a[i][j];
						nxt[i].id=j;
					}
				}
				
			}
			d[maxx[i].id]++;
			c[d[maxx[i].id]][maxx[i].id]=maxx[i].num-nxt[i].num;
		}
		long long sum[5]={0,0,0,0,0},ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=maxx[i].num;
			sum[maxx[i].id]++;
		}
		int pc=0,gh=0;
		for(int i=1;i<=3;i++)
		{
			if(sum[i]>n/2)
			{
				pc=i;
				gh=sum[i]-n/2;
				break;
			}
		}
		if(pc==0)
		{
			cout << ans << endl;
			qk(n);
			continue;
		}
		for(int i=1;i<=d[pc];i++)
		{
			p[i]=c[i][pc];
		}
		sort(p+1,p+d[pc]+1);
		for(int i=1;i<=gh;i++)
		{
			ans-=p[i];
		}
		cout << ans << endl; 
		qk(n);
	}
	return 0;
}
