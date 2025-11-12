//何昊雨铮 SN-S00025 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	char cc;
	while(1){cc=getchar();if(('0'<=cc&&cc<='9')||cc=='-')break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(!('0'<=cc&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
void print(int x)
{
	if(!x)putchar('0');
	if(x<0){x=-x;putchar('-');}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
}
const int N=2e5+5;
int t,n,a[N][3],maxn,ans,cnt,pt[N];
vector<int>num[3];
pair<int,int>b[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			maxn=0;
			for(int j=0;j<=2;j++)
			{
				a[i][j]=read();
				maxn=max(maxn,a[i][j]);
			}
			for(int j=0;j<=2;j++)
				if(maxn==a[i][j])
				{
					pt[i]=j;
					num[j].push_back(i);
					break;
				}
		}
		cnt=ans=0;
		if(num[0].size()*2>n)
		{
			for(int i=0;i<num[0].size();i++)
				b[++cnt]=make_pair(max(a[num[0][i]][1],a[num[0][i]][2])-a[num[0][i]][0],num[0][i]);
			sort(b+1,b+cnt+1);
			for(int i=cnt;i*2>n;i--)
				if(a[b[i].second][1]>a[b[i].second][2])pt[b[i].second]=1;
				else pt[b[i].second]=2;
		}
		else if(num[1].size()*2>n)
		{
			for(int i=0;i<num[1].size();i++)
				b[++cnt]=make_pair(max(a[num[1][i]][0],a[num[1][i]][2])-a[num[1][i]][1],num[1][i]);
			sort(b+1,b+cnt+1);
			for(int i=cnt;i*2>n;i--)
				if(a[b[i].second][0]>a[b[i].second][2])pt[b[i].second]=0;
				else pt[b[i].second]=2;
		}
		else if(num[2].size()*2>n)
		{
			for(int i=0;i<num[2].size();i++)
				b[++cnt]=make_pair(max(a[num[2][i]][0],a[num[2][i]][1])-a[num[2][i]][2],num[2][i]);
			sort(b+1,b+cnt+1);
			for(int i=cnt;i*2>n;i--)
				if(a[b[i].second][0]>a[b[i].second][1])pt[b[i].second]=0;
				else pt[b[i].second]=1;
		}
		for(int i=1;i<=n;i++)
			ans+=a[i][pt[i]];
		print(ans);	
		for(int i=0;i<=2;i++)
			num[i].clear();
	}
	

	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

