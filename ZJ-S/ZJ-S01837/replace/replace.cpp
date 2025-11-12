#include<bits/stdc++.h>
using namespace std;
const int maxl=5000010;
const int maxn=200010;
int n,q,ans;
typedef long long ll;
char s1[maxn][1010],s2[maxn][1010];
char t1[1010],t2[1010];
int p[maxn][1010];

void get_p(int x)
{
	int len=strlen(s1[x]+1);
	int j=0;
	for(int i=1;i<len;i++)
	{
		while(j>0 && s1[x][i+1]!=s1[x][j+1]) j=p[x][j];
		if(s1[x][i+1]==s1[x][j+1]) j++;
		p[x][i+1]=j;
	}
}

bool check(int x,int u)
{
	int v=u+strlen(s1[x]+1)-1;
	char t3[1010];
	for(int i=1;i<u;i++) t3[i]=t1[i];
	for(int i=u;i<=v;i++) t3[i]=s2[x][i-u+1];
	for(int i=v+1;i<=strlen(t1+1);i++) t3[i]=t1[i];
	for(int i=1;i<=strlen(t3+1);i++)
	{
		if(t3[i]!=t2[i]) return false;
	}
	return true;
}

void kmp(int x)
{
	int len2=strlen(s1[x]+1);
	int len1=strlen(t1+1);
	int j=0;
	for(int i=0;i<len1;i++)
	{
	    while(j>0 && t1[i+1]!=s1[x][j+1]) j=p[x][j];
		if(t1[i+1]==s1[x][j+1]) j++;
		if(j==len2)
		{
			if(check(x,(i+1)-len2+1)) ans++;
			j=p[x][j];
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]+1;
		cin>>s2[i]+1;
		get_p(i);
	}
	while(q--)
	{
		ans=0;
		cin>>t1+1;
		cin>>t2+1;
		for(int i=1;i<=n;i++)
		{
			if(strlen(s1[i]+1)>strlen(t1+1)) continue;
			kmp(i);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
