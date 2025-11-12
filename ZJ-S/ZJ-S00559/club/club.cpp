#include<bits/stdc++.h>
using namespace std;
#define N 100009
int T,n,len[3],sum;
struct id{int u,mx,nx;}s[N];
priority_queue<int>stk[3];
bool cmp(id A,id B)
{
	if(A.mx>B.mx) return true;
	return false;
}
int read()
{
	char ch=getchar();int sum=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while('0'<=ch&&ch<='9') sum=(sum<<3)+(sum<<1)+ch-'0',ch=getchar();
	return sum;
}
void write(int tmp)
{
	if(tmp>9) write(tmp/10);
	putchar(tmp%10+'0');
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		while(!stk[0].empty()) stk[0].pop();
		while(!stk[1].empty()) stk[1].pop();
		while(!stk[2].empty()) stk[2].pop();
		len[0]=len[1]=len[2]=sum=0;
		int a[3];
		for(int i=1;i<=n;i++)
		{
			a[0]=read(),a[1]=read(),a[2]=read();
			if(a[0]>=a[1]&&a[0]>=a[2]) s[i].u=0,s[i].mx=a[0];
			else if(a[1]>=a[0]&&a[1]>=a[2]) s[i].u=1,s[i].mx=a[1];
			else s[i].u=2,s[i].mx=a[2];
			sort(a,a+3);
			s[i].nx=s[i].mx-a[1];
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(len[s[i].u]<(n/2))
			{
				sum+=s[i].mx,len[s[i].u]++;
				stk[s[i].u].push(-s[i].nx);
			}
			else
			{
				int tp=-stk[s[i].u].top();
				stk[s[i].u].pop();
				if(tp<s[i].nx) sum+=s[i].mx-tp,stk[s[i].u].push(-s[i].nx);
				else sum+=s[i].mx-s[i].nx,stk[s[i].u].push(-tp);
			}
		}
		write(sum);putchar('\n');
	}
	return 0;
}