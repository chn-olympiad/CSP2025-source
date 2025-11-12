#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Beginning;

#define mp(x,y) make_pair(x,y)
#define PII pair<int,int>
#define se second
#define fi first

const int Base=613,mod=1e9+9;
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
const int N=2e5+5,M=5e6+100;
int n,m,Pw[M],len,cnt;
map<PII,int> Map;
//vector<PII> vec[M];

int GetMap(PII x)
{
	if(Map[x]==0) Map[x]=++cnt;
	return Map[x];
}

struct Hashing
{
	int S[M];
	int Get(int L,int R)
	{
		if(L>R || L<0 || R>len) return 0;
		return ((S[R]-S[L-1]*Pw[R-L+1])%mod+mod)%mod;
	}
	void init(string s)
	{
		for(int i=1;i<=len;i++) S[i]=(S[i-1]*Base+s[i-1])%mod;
	}
}Hash[2];
void init(int n)
{
	int i; Pw[0]=1;
	for(i=1;i<=n;i++) Pw[i]=Pw[i-1]*Base%mod;
}

bool check(int L,int R)
{
	if(L>R) return true;
	return Hash[0].Get(L,R)==Hash[1].Get(L,R); 
}

int GetLeft()
{
	int left=0,right=len;
	while(left<right)
	{
		int mid=(left+right+1>>1);
		if(check(1,mid)) left=mid;
		else right=mid-1;
	}
	return left+1;
}
int GetRight()
{
	int left=1,right=len+1;
	while(left<right)
	{
		int mid=(left+right>>1);
		if(check(mid,len)) right=mid;
		else left=mid+1;
	}
	return left-1;
}

struct Node
{
	int x,y,L,R,Lx,Rx;
	bool friend operator <(const Node &a,const Node &b)
	{
		return a.x<b.x;
	}
};

Node GetTrue(string s,string t)
{
	Hash[0].init(s),Hash[1].init(t);
	int L=GetLeft(),R=GetRight(); //if(flag<10) cerr<<L<<' '<<R<<'\n';
	return (Node){
		Hash[0].Get(L,R),Hash[1].Get(L,R),
		L,R,Hash[0].Get(1,L-1),Hash[1].Get(R+1,len)
	};
}

int Count(string s)
{
	int i,cnt=0;
	for(i=0;i<len;i++)
	{
		if(s[i]!='a')
		cnt++;
	}
	return cnt;
}

map<Node,int> Mp;
void Insert(Node P)
{
	P.L--,P.R=len-P.R;
	Mp[P]++;
}

//int SubTask1Solve(Node x)
//{
//	
//}

int Query(Node P)
{
	int ans=0;
	for(auto i:Mp)
	{
		Node Now=i.fi;
		if(P.x==Now.x && P.y==Now.y && Hash[0].Get(P.L-Now.L,P.L-1)==Now.Lx && Hash[1].Get(P.R+1,P.R+Now.R)==Now.Rx)
		ans+=i.se;
	}
	return ans;
}

bool Ending;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace1.in","r",stdin);
//	freopen("Lydia.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int i,Now; string s,t;
	cin>>n>>m; init(M-5);
	for(i=1;i<=n;i++)
	{
		cin>>s>>t; len=s.size();
//		Hash[0].init(s),Hash[1].init(t);
//		P[++cnt]=mp(Hash[0].Get(1,len),Hash[1].Get(1,len));
//		Map[mp(Hash[0].Get(1,len),Hash[1].Get(1,len))]++;
		Insert(GetTrue(s,t));
//		Cnt=max(Cnt,max(Count(s),Count(t)));
	}
	for(i=1;i<=m;i++)
	{
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<"0\n";
			continue;
		}
		len=s.size();
//		Hash[0].init(s),Hash[1].init(t);
//		for(k=1;k<=len;k++)
//		{
//			for(Now=1;Now<=n;Now++)
//			{
//				if(Hash[0].Get(k,k+))
//			}
//		}
//		Cnt=max(Cnt,max(Count(s),Count(t)));
//		if(Cnt==1) cout<<SubTask1Solve(GetTrue(s,t))<<'\n';
//		else
		cout<<Query(GetTrue(s,t))<<'\n';
	}
	cerr<<"\nused "<<(abs(&Ending-&Beginning)/1048576)<<" MB\n";
	return 0;
}
