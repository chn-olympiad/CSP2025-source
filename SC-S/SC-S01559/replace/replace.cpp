#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,q;
int dis1[N],dis2[N],len[N];
string s1[N],s2[N],t1,t2;
inline int read()
{
	int k=0;
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	while(c>=48 && c<=57) k=(k<<3ll)+(k<<1ll)+c-48ll,c=getchar();
	return k;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].length();
		for(int j=0;j<len[i];j++)
		{
			if(s1[i][j]=='b') dis1[i]=j;
			if(s2[i][j]=='b') dis2[i]=j;
		}
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int lth=t1.length(),pos1=0,pos2=0;
		for(int i=0;i<lth;i++)
		{
			if(t1[i]=='b') pos1=i;
			if(t2[i]=='b') pos2=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(pos2-pos1==dis2[i]-dis1[i] && dis2[i]<=pos2 && dis1[i]<=pos1 && pos1+len[i]-dis1[i]<=lth && pos2+len[i]-dis2[i]<=lth) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/