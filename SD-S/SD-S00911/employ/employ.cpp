#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline string reads()
{
	string s;
	char c=getchar();
	while(c<'0'||'1'<c) c=getchar();
	while('0'<=c&&c<='1'){
		s=s+c;
		c=getchar();
	}
	return s;
}
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const long long P=998244353;
int n,m,t[508],vis[508];
int p[508];
string s;
long long ans;
void solve1(int x)
{
//	cout<<1;
	if(x>n)
	{
		int pst=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||pst>=t[p[i]]) pst++;
		}
		if(n-pst>=m) ans=(ans+1)%P;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			solve1(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	s=" ";
	s=s+reads();
	for(int i=1;i<=n;i++) t[i]=read();
	if(n<=10)
	{
//		cout<<1;
		solve1(1);
		write(ans);
		return 0;
	}
	bool fA=0;
	for(int i=1;i<=n;i++) if(s[i]=='0'){fA=1;break;}
	if(!fA)
	{
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%P;
		write(ans);
		return 0;
	}
	return 0;
}
