#include<bits/stdc++.h>
using namespace std;
long long n,x,k,MAX,ans,z,k2,MAXX;
string st,s[500010],sk;
struct node
{
	int s,e;
}a[100010];
int cmp(node a,node b)
{
	if(a.s==b.s) return a.e<b.e;
	  else return a.s<b.s;
}
void dfs(int f,long long sum)
{
	for(int j=f+1;j<=ans;j++)
	{
		if(a[f].e<a[j].s) dfs(j,sum+1);
	}
	MAXX=max(MAXX,sum);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k2=k;
	while(k2>0)
	{
		sk+=k2%2+'0';
		k2/=2;
	}
	MAX=sk.size();
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==k)
		{
			a[++ans].s=i;
			a[ans].e=i;
		}
		if(x==0) s[i]='0';
		while(x>0)
		{
			s[i]+=x%2+'0';
			x/=2;
		}
		z=s[i].size();
		MAX=max(MAX,z);
	}
	z=sk.size();
	while(z<MAX)
	{
		sk+='0';
		z++;
	}
	for(int i=1;i<=n;i++)
	{
		while(s[i].size()<MAX)
		{
			s[i]+='0';
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			st=s[i];
			for(int t=i+1;t<=j;t++)
			{
				for(int o=0;o<s[t].size();o++)
				{
					if(st[o]==s[t][o]) st[o]='0';
					  else st[o]='1';
				}
			}
			if(st==sk)
			{
				a[++ans].s=i;
				a[ans].e=j;
			}
		}
	}
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans;i++)
	{
		dfs(i,1);
	}
	cout<<MAXX<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}