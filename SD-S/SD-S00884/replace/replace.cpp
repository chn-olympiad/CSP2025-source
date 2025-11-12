#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define ll __int128
using namespace std;
const ll mod=10000002476911877;
const int B=131;
const int N=2e5+10;
bool MEM1;
int n,m,s,l,ans[N],tp;
vector<char>qwq;
map<ll,int>mp;
vector<int>S[N],T[N];
inline int read()
{
	char x=getchar();
	int ans=0;
	while(x<'0'||x>'9')
		x=getchar();
	while(x>='0'&&x<='9')
	{
		ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
struct str
{
	vector<char>vec;
	int n;
	char &operator[](int x)
	{
		return vec[x-1];
	}
	void operator+=(char x)
	{
		n++;
		vec.push_back(x);
	}
	void input()
	{
		n=0;
		vec.clear();
		char x=getchar();
		while(x<'a'||x>'z')
			x=getchar();
		while(x>='a'&&x<='z')
		{
			vec.push_back(x);
			n++;
			x=getchar();
		}
	}
	void output()
	{
		for(int i=1;i<=n;i++)
			putchar(vec[i-1]);
		puts("");
	}
}X,Y;
bool checkpre(str A,str B)
{
	if(A.n>B.n)
		return false;
	for(int i=1;i<=A.n;i++)
	{
		if(A[i]!=B[i])
			return false;
	}
	return true;
}
struct query
{
	int id;
	str s1,s2;
	ll val;
}a[N],b[N];
void getX(str A,str B,int &fr,int &ba)
{
	for(fr=1;fr<=A.n;fr++)
	{
		if(A[fr]!=B[fr])
		{
			fr--;
			break;
		}
	}
	for(ba=A.n;ba>=1;ba--)
	{
		if(A[ba]!=B[ba])
		{
			ba++;
			break;
		}
	}
}
void inser(ll &x,int a)
{
	x=(x*B%mod+a)%mod;
}
vector<ll>B1[N],B2[N];
ll A1[N],A2[N];
void solve(vector<int>A,vector<int>B)
{
//	cout<<A.size()<<" "<<B.size()<<endl;
	for(int x:A)
	{
		A1[x]=A2[x]=0;
		for(int i=1;i<=a[x].s1.n;i++)
			inser(A1[x],a[x].s1[i]);
		for(int i=1;i<=a[x].s2.n;i++)
			inser(A2[x],a[x].s2[i]);
	}
	for(int x:B)
	{
		B1[x].resize(b[x].s1.n+1);
		B2[x].resize(b[x].s2.n+1);
		for(int i=1;i<=b[x].s1.n;i++)
		{
			B1[x][i]=B1[x][i-1];
			inser(B1[x][i],b[x].s1[i]);
		}
		for(int i=1;i<=b[x].s2.n;i++)
		{
			B2[x][i]=B2[x][i-1];
			inser(B2[x][i],b[x].s2[i]);
		}
	}
	for(int x:A)
	{
		for(int y:B)
		{
			if(a[x].s1.n<=b[y].s1.n&&A1[x]==B1[y][a[x].s1.n]
			 &&a[x].s2.n<=b[y].s2.n&&A2[x]==B2[y][a[x].s2.n])
			{
				ans[b[y].id]++;
			}
		}
	}
	return ;
}
bool MEM2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		X.input();
		Y.input();
		int fr,ba;
		getX(X,Y,fr,ba);
		for(int j=fr+1;j<ba;j++)
			inser(a[i].val,X[j]);
		inser(a[i].val,'z'+1);
		for(int j=fr+1;j<ba;j++)
			inser(a[i].val,Y[j]);
		for(int j=fr;j>=1;j--)
			a[i].s1+=X[j];
		for(int j=ba;j<=X.n;j++)
			a[i].s2+=X[j];
		if(!mp[a[i].val])
			mp[a[i].val]=++tp;
		S[mp[a[i].val]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		X.input();
		Y.input();
		int fr,ba;
		getX(X,Y,fr,ba);
		b[i].id=i;
		if(X.n!=Y.n)
			b[i].val=-1;
		else
		{
			for(int j=fr+1;j<ba;j++)
				inser(b[i].val,X[j]);
			inser(b[i].val,'z'+1);
			for(int j=fr+1;j<ba;j++)
				inser(b[i].val,Y[j]);
			for(int j=fr;j>=1;j--)
				b[i].s1+=X[j];
			for(int j=ba;j<=X.n;j++)
				b[i].s2+=X[j];
		}
		if(mp.find(b[i].val)!=mp.end())
			T[mp[b[i].val]].push_back(i);
	}
	for(int i=1;i<=tp;i++)
	{
		solve(S[i],T[i]);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
}
