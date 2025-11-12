#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,c[N];
string s;
int f()
{
	int sum=1;
	for(int i=n-m+1;i<=n;i++) sum=(sum*i)%mod;
	//for(int i=1;i<=m;i++) sum=(sum*i)%mod;
	return sum%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];	
		if(c[i]==0) cnt++;	
	}
	if(n==m) 
	{
		cout<<1<<endl;
		return 0;
	} 
	n-=cnt;
	if(n<=m) 
	{
		cout<<1<<endl;
		return 0;
	} 
	cout<<f()<<endl;
	return 0;
}
/*
n!/(n-m)!
*/
