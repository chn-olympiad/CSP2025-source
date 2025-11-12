#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+9,L=5e6+9;
struct memory{
	int l,r,dl,dr;
}A[N],B[N],S[N],T[N];
char cA[L],cB[L],cS[L],cT[L];
int topA,topB,topS,topT;

int que[L],plS[L],plT[L],visA[L],visB[L];

int n,q,ans;

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

0
0
0
0
*/
/*
1 2
aab abb
aabaa abbaa
aaaab aaabb

1
1
*/

inline bool check();
inline int  upper(int x);
inline int  lower(int x);

inline void update(int l,int r,int w);
inline void solve(int w);

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace4.in","r",stdin);
//	freopen("replace4.out","w",stdout);
	
	scanf ("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf ("%s",cA+topA+1),A[i]={topA+1,strlen(cA+1)},topA=strlen(cA+1);
		scanf ("%s",cB+topB+1),B[i]={topB+1,strlen(cB+1)},topB=strlen(cB+1);
	}
	for (int i=1;i<=q;i++)
	{
		scanf ("%s",cS+topS+1),S[i]={topS+1,strlen(cS+1)},topS=strlen(cS+1);
		scanf ("%s",cT+topT+1),T[i]={topT+1,strlen(cT+1)},topT=strlen(cT+1);
	}
	
	if (!check())
	{
		for (int i=1;i<=q;i++)
			update(S[i].l,S[i].r,i);
		for (int i=1;i<=q;i++)
			if (S[i].r-S[i].l==T[i].r-T[i].l)
				solve(i);
			else
				puts("0");
	}
	
	return 0;
}

inline bool check()
{
	int g;
	for (int i=1;i<=n;i++)
	{
		g=0;
		for (int j=A[i].l;j<=A[i].r;j++)
		{
			if (cA[j]>'b')
				return false;
			g+=(cA[j]=='b');
		}
		if (g!=1)
			return false;
			
		g=0;
		for (int j=B[i].l;j<=B[i].r;j++)
		{
			if (cB[j]>'b')
				return false;
			g+=(cB[j]=='b');
		}
		if (g!=1)
			return false;
	}
	for (int i=1;i<=q;i++)
	{
		g=0;
		for (int j=S[i].l;j<=S[i].r;j++)
		{
			if (cS[j]>'b')
				return false;
			g+=(cS[j]=='b');
		}
		if (g!=1)
			return false;
			
		g=0;
		for (int j=T[i].l;j<=T[i].r;j++)
		{
			if (cT[j]>'b')
				return false;
			g+=(cT[j]=='b');
		}
		if (g!=1)
			return false;
	}
	
	int u,v;
	for (int i=1;i<=n;i++)
	{
		for (int j=A[i].l;j<=A[i].r;j++)
			if (cA[j]=='b')
				u=j;
		for (int j=B[i].l;j<=B[i].r;j++)
			if (cB[j]=='b')
				v=j;
		que[i]=u-v;
	}
	stable_sort(que+1,que+n+1);
	
	for (int i=1;i<=q;i++)
	{
		for (int j=S[i].l;j<=S[i].r;j++)
			if (cS[j]=='b')
				u=j;
		for (int j=T[i].l;j<=T[i].r;j++)
			if (cT[j]=='b')
				v=j;
		if (S[i].r-S[i].l!=T[i].r-T[i].l)
			puts("0");
		else
		{
			int x=upper(u-v)-lower(u-v)+1;
			printf ("%d\n",max(0,x));
		}
	}
}

inline int upper(int x)
{
	int l=1,r=n,mid,res=0;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (que[mid]<=x)
			l=mid+1;
		else
			r=mid-1;
		if (que[mid]==x)
			res=mid;
	}
	return res;
}

inline int lower(int x)
{
	int l=1,r=n,mid,res=n+1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (que[mid]>=x)
			r=mid-1;
		else
			l=mid+1;
		if (que[mid]==x)
			res=mid;
	}
	return res;
}

inline void update(int l,int r,int w)
{
	for (int i=l;i<=r;i++)
		if (cS[i]==cT[i])
			S[w].dl++;
		else
			break;
	for (int i=r;i>=l;i--)
		if (cS[i]==cT[i])
			S[w].dr++;
		else
			break;
	
	plS[l]=plT[l]=l-1;
	for (int i=l+1,j=l-1;i<=r;i++)
	{
		while (j>=l and cS[j+1]!=cS[i])
			j=plS[j];
		if (cS[j+1]==cS[i])
			j++;
		plS[i]=j;
	}
	for (int i=l+1,j=l-1;i<=r;i++)
	{
		while (j>=l and cT[j+1]!=cT[i])
			j=plT[j];
		if (cT[j+1]==cT[i])
			j++;
		plT[i]=j;
	}
}

inline void solve(int w)
{
	int l,r,res=0;
	
	for (int t=1;t<=n;t++)
	{
		l=A[t].l,r=A[t].r;
		for (int i=S[w].l,j=l-1;i<=S[w].r;i++)
		{
			while (j>=l and cA[j+1]!=cS[i])
				j=plS[j];
			if (cA[j+1]==cS[i])
				j++;
			visA[i]=j-l+1;
		}
		for (int i=T[w].l,j=l-1;i<=T[w].r;i++)
		{
			while (j>=l and cB[j+1]!=cT[i])
				j=plT[j];
			if (cB[j+1]==cT[i])
				j++;
			visB[i]=j-l+1;
		}
		
		for (int i=S[w].l;i<=S[w].r;i++)
		{
			if (visA[i]==visB[i] and visA[i]==r-l+1)
			{
				if (i-(r-l)<=S[w].l+S[w].dl and S[w].r-S[w].dr<=i)
				{
					res++;
					break;
				}
			}
		}
	}
	printf ("%d\n",res);
}

