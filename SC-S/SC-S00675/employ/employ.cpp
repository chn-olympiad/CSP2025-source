#include <bits/stdc++.h>
using namespace std;

const int K=998244353;

int n,m;
int ans=0;
char d[505];
int pt[505]={};
bool c[505]={};

void test(int k,int t,int f,int w)
{
	if(f>=pt[k])
		f++;
	else
	{
		if(d[t-1]=='0')
			f++;
		else
			w++;
	}
	if(t==n)
	{
		if(w==m)
			ans=(ans+1)%K;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!c[i])
		{
			c[i]=1;
			test(i,t+1,f,w);
			c[i]=0;
		}
	}
	return;
}

signed int main(void)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",d);
	for(int i=1;i<=n;i++)
		scanf("%d",pt+i);
	for(int i=1;i<=n;i++)
	{
		c[i]=1;
		test(i,1,0,0);
		c[i]=0;
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 