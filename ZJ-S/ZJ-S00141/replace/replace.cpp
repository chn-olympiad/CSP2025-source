#include<bits/stdc++.h>
using namespace std;

int n,q,ans;
struct node
{
	char s1[5000011],s2[5000011];
	int p[5000011];
}s[200001];
char ss[5000011],se[50000011];

void pre(int m)
{
	s[m].p[1]=0;
	int j=0;
	for(int i=1;i<strlen(s[m].s1);i++)
	{
		while(j!=0&&s[m].s1[i+1]!=s[m].s1[j+1]) j=s[m].p[j];
		if(s[m].s1[i+1]==s[m].s1[j+1]) j++;
		s[m].p[i+1]=j;
	}
}
int kmp(int m)
{
	int j=0;
	for(int i=1;i<=strlen(se);i++)
	{
		while(j!=0&&s[m].s1[j+1]!=se[i+1]) j=s[m].p[j];
		if(s[m].s1[j+1]==se[i+1]) j++;
		if(j==strlen(s[m].s1)) return i+1-j;
	}
}

void solve()
{
	char sss[5000011];
	for(int i=1;i<=n;i++)
	{
		strcpy(sss,ss);
		int f=kmp(i);
		int j=0;
		for(int i=f;i<=f+strlen(s[i].s1);i++) sss[i]=s[i].s2[++j];
		if(strcmp(sss,se)==1) ans++;
	}
	cout<<ans;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i].s1+1>>s[i].s2+1;
		pre(i);	
	}
	while(q)
	{
		q--;
		cin>>ss+1>>se+1;
		solve();
	}
	return 0;
}
