#include<bits/stdc++.h>
#include<chrono>
#define ll long long
#define pb push_back
#define mp make_pair
#define ms microseconds
#define N 505
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
const int mod= 998244353 ; 
int a[N],c[N],n,m;
char s[N];
int Mul(int x,int y){return (ll)x*y%mod;}
int Add(int x,int y){return (x+y>=mod)?x+y-mod:x+y;}
namespace sub1
{
	int ans,book[12],a[12];
	bool check()
	{
		int i,j,cnt=0,g=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1'&&g<c[a[i]]) cnt++;
			else g++;  
		}
		return cnt>=m;
	}
	void dfs(int cnt)
	{
		if(cnt==n+1) 
		{
//			for(int i=1;i<=n;i++) printf("%d ",a[i]);
//			printf("jie=%d\n",t);
			if(check()) ans++;
			return ;
		}
		for(int i=1;i<=n;i++) 
		{
			if(book[i]) continue;
			a[cnt]=i; book[i]=1;
			dfs(cnt+1);
			book[i]=0;
		}
	}
	int Sol()
	{
		dfs(1);
		printf("%d",ans);
	}
}
namespace sub2
{
	int wei[20],len,xuan[20],mins[20];
	vector<int>v;
	int ke[20],ans;
	bool book[20];	
	int getnum(int ge)
	{
//		printf("ge=%d\n",ge);
		memset(ke,0,sizeof(ke));
		int i,j,ans=1;
		for(i=1;i<=ge;i++) mins[i]=xuan[i]-i;

		for(i=1;i<=ge;i++)
		{
			for(j=1;j<=n;j++)
			if(c[j]>mins[i]) ke[i]++;
			if(ke[i]-(ge-i)<=0) return 0;//无法做到选出足够的 
		}
//		for(i=1;i<=ge;i++) printf("%d ",xuan[i]);printf("\n");
//		for(i=1;i<=ge;i++) printf("%d ",mins[i]);printf("\n");
//		for(i=1;i<=ge;i++) printf("%d ",ke[i]);printf("\n");
		for(i=ge;i>=1;i--)  ans=Mul(ans,ke[i]-(ge-i));//倒着选取 
		for(i=1;i<=(n-ge);i++) ans=Mul(ans,i);//剩下的全排
		return ans; 
	}
	void dfs(int cnt,int ge)
	{
		if(cnt==len+1) 
		{
			if(ge<m) return ;
			ans=Add(ans,getnum(ge));
			return ;
		}
		dfs(cnt+1,ge);
		xuan[ge+1]=wei[cnt];
		dfs(cnt+1,ge+1);//选中的位置 
	}
	int Sol()
	{
		int i,j;
		for(i=1;i<=n;i++) if(s[i]=='1') wei[++len]=i;
		dfs(1,0);
		printf("%d",ans);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,flag1=1,cnts1=0;
	n=read(),m=read();
	scanf("%s",s+1);
	for(i=1;i<=n;i++) c[i]=read();
	for(i=1;i<=n;i++) 
	if(s[i]=='0') flag1=0;//不是全部可以被录取 
	else cnts1++;
	if(n<=10) sub1::Sol();
	else if(cnts1<=18) sub2::Sol();
	else if(flag1) 
	{
		int ans=1,cnt=0;
		for(i=1;i<=n;i++) if(c[i]) cnt++;
		for(i=1;i<=cnt;i++) ans=Mul(ans,i);//阶乘，启动 
		printf("%d",ans);
	}
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


3 2
101
1 1 2

*/


