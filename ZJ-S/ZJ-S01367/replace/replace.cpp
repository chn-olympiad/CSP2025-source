#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
ULL p[5000010],h1[5000010],h2[5000010],H1[5000010],H2[5000010];
int n,q,len[200010];
string s1[200010],s2[200010],t1,t2;
inline ULL get(int l,int r)
{
	return H1[r]-H1[l-1]*p[r-l+1];
}
inline ULL Get(int l,int r)
{
	return H2[r]-H1[l-1]*p[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=5000005;i++)p[i]=p[i-1]*131;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		for(int j=1;j<=len[i];j++)
		{
			h1[i]=h1[i]*131+s1[i][j];
			h2[i]=h2[i]*131+s2[i][j];
		}
	}
	while(q--)
	{
		cin>>t1>>t2;
		int m=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int minn=n+1,maxn=0;
		for(int i=1;i<=m;i++)
		{
			H1[i]=H1[i-1]*131+t1[i];
			H2[i]=H2[i-1]*131+t2[i];
			if(t1[i]!=t2[i])
			{
				minn=min(minn,i);
				maxn=max(maxn,i);
			}
		}
		int L=minn,R=maxn;
		ULL str1=get(L,R),str2=Get(L,R);
		long long res=0;
//		cout<<"LR:"<<L<<" "<<R<<'\n';
		for(int i=1;i<=n;i++)
		{
//			cout<<"hi:"<<i<<' '<<h1[i]<<' '<<h2[i]<<"\n";
			if(len[i]>m)continue;
			for(int j=max(1,R-len[i]+1);j<=L;j++)
			{
				if(j+len[i]-1>m)continue;
				if(h1[i]==get(j,j+len[i]-1)&&h2[i]==Get(j,j+len[i]-1))
				{
//					cout<<"ij:"<<i<<' '<<j<<' '<<j+len[i]-1<<' '<<h1[i]<<' '<<get(j,j+len[i]-1)<<'\n';
					res++;
				}
			}
		}
		print(res);
		puts("");
	}
}
