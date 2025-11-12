#include<bits/stdc++.h>
#include<chrono>
#define ll long long 
#define pb push_back
#define mp make_pair
#define ms microseconds
#define fi first 
#define se second
#define N 300005
using namespace std;
using namespace chrono;
auto Star=system_clock::now();
auto GetTime(){return (double)(duration_cast<ms>(system_clock::now()-Star).count())*ms::period::num/ms::period::den;}
void PrintTime(){cout<<"Cost="<<GetTime()<<"s."<<endl;}
int read()
{
	int t=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) t=t*10+ch-48,ch=getchar();
	return t*f;	
}
int cnt[4];
bool book[N];
vector<pair<int,int> >v[4];
struct node2{int num,ren,tp;}b[N<<1];
bool cmp(node2 x,node2 y)
{
	if(x.num==y.num) return x.tp<y.tp;
	return x.num>y.num;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	int T=read();
	while(T--)
	{
		int n=read();int len=0,t=0,ans=0;
		
		memset(cnt,0,sizeof(cnt));memset(book,0,sizeof(book));memset(b,0,sizeof(b));
		for(i=1;i<=3;i++) while(v[i].size()) v[i].pop_back();
		
		for(i=1;i<=n;i++) 
		{
			int x=read(),y=read(),z=read();
			b[++len]=(node2){x,i,1};b[++len]=(node2){y,i,2};b[++len]=(node2){z,i,3};//要保证一个人只会被放到一个v里 
			if(x>=y&&x>=z)//1最大，其中的与第二的差值 。相等的情况随便归类即可 
			{
				if(y>=z) v[1].pb(mp(x-y,2));
				else v[1].pb(mp(x-z,3));
			}
			else if(y>=x&&y>=z)
			{
				if(x>=z) v[2].pb(mp(y-x,1));
				else v[2].pb(mp(y-z,3));
			}
			else 
			{
				if(x>=y) v[3].pb(mp(z-x,1));
				else v[3].pb(mp(z-y,2));
			}
		}
		
		sort(b+1,b+1+len,cmp);
		sort(v[1].begin(),v[1].end());//让减小的值越小越好
		sort(v[2].begin(),v[2].end());
		sort(v[3].begin(),v[3].end());
		 
		for(i=1;i<=len;i++)
		{
			node2 x=b[i]; if(book[x.ren]) continue;
			book[x.ren]=1;cnt[x.tp]++;ans+=x.num;
			if(cnt[x.tp]>n/2)
			{
				ans-=v[x.tp][t].fi;
				cnt[x.tp]--;cnt[v[x.tp][t].se]++;//种类转换
				t++; //应当只会有一个需要转移的种类 
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
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
