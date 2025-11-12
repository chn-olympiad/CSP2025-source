#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1e1;
string s1[N],s2[N],t1,t2;
inline void read_string(string &s)
{
 char c=getchar();	s="";
 while(c<'a'||c>'z')	c=getchar();
 while(c>='a'&&c<='z')
 	s+=c,c=getchar();
}
inline void read(int &x)
{
 char c=getchar();	x=0;
 while(c<'0'||c>'9')	c=getchar();
 while(c>='0'&&c<='9')
 	x=(x<<3)+(x<<1)+c-48,c=getchar();
}
int sameL[N],sameR[N],Len[N];
inline int check(int L,int k)
{
 for(int i=L;i<L+Len[k];i++)
 	if(t1[i]!=s1[k][i-L])	return 0;
 for(int i=L;i<L+Len[k];i++)
 	if(t2[i]!=s2[k][i-L])	return 0;
 return 1;
}
bool special=true;
inline void check_special(string s1)
{
 int tag=0;
 for(int i=0;i<s1.size();i++)
 {
 	if(s1[i]!='a'&&s1[i]!='b'||(s1[i]!='a'&&tag==1))
	{
		special=false;
		return ;
	}	
	if(s1[i]!='a')	tag=1;
 }
 return ;
}
int main()
{
 freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
 int n,q;	read(n),read(q);
 for(int i=1;i<=n;i++)
 {
 	read_string(s1[i]),read_string(s2[i]),Len[i]=s1[i].size();
 	if(special)	check_special(s1[i]),check_special(s2[i]);
 }
 for(int i=1;i<=n;i++)
 {
 	for(int j=0;j<Len[i];j++)
 	{
 		if(s1[i][j]!=s2[i][j])	break;
 		sameL[i]++;
	}
	for(int j=Len[i]-1;j>=0;j--)
	{
		if(s1[i][j]!=s2[i][j])	break;
		sameR[i]++;
	}
 }
 int sL,sR,len;
 while(q--)
 {
 	read_string(t1),read_string(t2);	sL=0,sR=0,len=t1.size();
 	if(special)
 		check_special(t1),check_special(t2);
 	if(t1.size()!=t2.size())
 	{
 		printf("0\n");
 		continue;
	}
	for(int i=0;i<len;i++)
	{
		if(t1[i]!=t2[i])	break;
		sL++;
	}
	for(int i=len-1;i>=0;i--)
	{
		if(t1[i]!=t2[i])	break;
		sR++;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(Len[i]-(sameL[i]+sameR[i])!=len-sL-sR)	continue;
		if(sL<sameL[i]||sR<sameR[i])				continue;
		if(special)
		{
			if(t1[sL]==s1[i][sameL[i]]&&t2[len-sR-1]==s2[i][Len[i]-sameR[i]-1])	res++;
			continue;
		}
		res+=check(sL-sameL[i],i);
	}
	printf("%lld\n",res);
 }
 return 0;
}
