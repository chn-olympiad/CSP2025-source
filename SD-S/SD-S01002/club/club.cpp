#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Beginning;

#define mp(x,y) make_pair(x,y)
#define PII pair<int,int>
#define se second
#define fi first

namespace Memory_Love{
	int read(){ int x=0; bool flag=1; char ch=getchar();
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag? x:-x);}
	void write(int x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
	int gcd(int a,int b){return (b==0? a:gcd(b,a%b));}
	int lcm(int a,int b){return a/gcd(a,b)*b;}
	int ksm(int a,int b,int p){int ans=1%p;while(b){if(b&1) ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
	int exgcd(int a,int b,int &x,int &y){if(!b){x=1,y=0; return a;}int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
} using namespace Memory_Love;
const int N=1e5+5,INF=0x3f3f3f3f3f3f3f3fll;
int n,m; 
struct Node
{
	int A[5],Now;
	int Max(){return max({A[1],A[2],A[3]});}
	int Min(){return min({A[1],A[2],A[3]});}
	int Sec(){return A[1]+A[2]+A[3]-Max()-Min();}
	
	int MaxBelong()
	{
		if(Max()==A[1]) return 1;
		if(Max()==A[2]) return 2;
		if(Max()==A[3]) return 3;
		return -1;
	}
	int SecBelong()
	{
		if(Sec()==A[3]) return 3;
		if(Sec()==A[2]) return 2;
		if(Sec()==A[1]) return 1;
		return -1;
	}
	int MinBelong()
	{
		return 6-MaxBelong()-SecBelong();
	}
	int Val()
	{
		if(Now==1) return Max()-Sec();
		if(Now==2) return Sec()-Min();
		return -INF;
	}
	int NexBelong()
	{
		if(Now==1) return SecBelong();
		if(Now==2) return MinBelong();
		return -1;
	}
	bool friend operator <(Node a,Node b)
	{
		return a.Val()>b.Val();
	}
}a[N];
bool Ncomp(Node a,Node b)
{
	return a.Max()<b.Max();
} 

priority_queue<Node> q[5];
void init()
{
	for(int i=1;i<=3;i++)
	{
		while(q[i].size()) q[i].pop();
	}
}

int MainSolve()
{
	int i,j,ans=0; n=read(); init();
	for(i=1;i<=n;i++)
	{
		a[i].Now=1;
		for(j=1;j<=3;j++)
		a[i].A[j]=read();
	}
	sort(a+1,a+1+n,Ncomp);
	for(i=1;i<=n;i++)
	{
		//puts("dwzbssssm");
		int x=a[i].MaxBelong();
		q[x].push(a[i]); ans+=a[i].Max();
		//puts("zxbakCSPS");
		while(q[x].size()>n/2)
		{
			Node P=q[x].top(); q[x].pop(); //puts("1");
			ans-=P.Val(); //puts("2");
			P.Now++; //cerr<<P.Now<<"sfasfs\n";
			x=P.NexBelong(); //puts("4");
			q[x].push(P); //puts("5");
//			cerr<<x<<' '<<q[x].size()<<'\n';
		}
//		puts("lzhbssssm");
	}
	return ans;
}

bool Ending;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
	int T=read(); while(T--) write(MainSolve(),'\n');
	cerr<<"\nused "<<(abs(&Ending-&Beginning)/1048576)<<" MB\n";
	return 0;
}
