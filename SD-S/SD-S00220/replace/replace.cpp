#include<bits/stdc++.h>
using namespace std;
long long cins()
{
	long long cnt=1;
	char c=getchar();
	while(c^'b')
	{
		c=getchar();
		cnt++;
	}
	return cnt;
}
long long n,q;
long long yong[2][5000050];
struct st
{
	long long a,b;
};
st jil[200050];
bool cmp(st a,st b)
{
	return a.a<b.b;
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);

	scanf("%lld%lld",&n,&q);
	long long z=0;
	for(int i=0;i<n;i++)
	{
		jil[z].a=cins();
		jil[z++].b=cins();
	}
	sort(jil,jil+n,cmp);
	long long gong=0;
	for(int i=1;i<z;i++)
	{
		if(jil[i].a^jil[i-1].a)
		{
			yong[0][jil[i].a]=i;
			yong[1][gong]=i;
			gong=jil[1][i];
		}
	}
	long long a,b;
	for(int i=0;i<q;i++)
	{
		a=cins();
		b=cins();
		if(a==b)
		{
			printf("%d\n",n-yong[0][a]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

