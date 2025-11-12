#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
string sa[N],sb[N];
char st[M],ta[M],tb[M];
int n,q,le[N];
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
void grpas(int id)
{
	int i;
	scanf("%s",st+1);le[id]=strlen(st+1);
	sa[id]+='#';sb[id]+='#';
	for(i=1;st[i];i++)
	sa[id]+=st[i];
	scanf("%s",st+1);
	for(i=1;st[i];i++)
	sb[id]+=st[i];
}
void solve1()
{
	int i,j,k,len,ans;
	bool tg;
	while(q--)
	{
		scanf("%s",ta+1);scanf("%s",tb+1);
		ans=0;len=strlen(ta+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=len-le[i]+1;j++)
			{
				tg=1;
				for(k=1;k<=len;k++)
				{
					if(k>=j&&k<=j+le[i]-1)
					{
						if(ta[k]==sa[i][k-j+1]&&sb[i][k-j+1]==tb[k])
						continue;
						tg=0;
						break;
					}
					else
					if(ta[k]!=tb[k])
					{
						tg=0;
						break;
					}
				}
				ans+=tg;
			}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i;
	n=read();q=read();
	for(i=1;i<=n;i++)
	grpas(i);
	if(q<=100)
	{
		solve1();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
