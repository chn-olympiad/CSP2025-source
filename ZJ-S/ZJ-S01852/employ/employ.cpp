#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int t=0,n,q,ans=0,a[100010];
string p;
bool solve()
{
	int qu=0,lu=0;
	for(int i=1;i<=n;i++)
	{
		if(qu<a[i]&&p[i-1]=='1') lu++;
		else qu++;
	}
	if(lu>=q) return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();q=read();
	while(t<n) {p[t]=getchar();t++;}
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	while(1)
	{
		if(solve()) ans++;
		if(!next_permutation(a+1,a+n+1)) break;
		next_permutation(a+1,a+n+1);
	}
	cout<<ans;
	return 0;
}
