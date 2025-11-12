#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,m1=131,m2=97,maxl=5e6+5;
const long long mod=1e15+37;
int n,q,len[maxn],ans,z[maxn],y[maxn];
string s1[maxn],s2[maxn];
char t1[maxl],t2[maxl];
long long h1[maxn],h2[maxn];
unordered_map<long long,unordered_map<long long,vector<int> > >mp;
string read()
{
	string s="";
	char c=getchar();
	while(c>'z'||c<'a')
	  c=getchar();
	while(c<='z'&&c>='a')
	  s=s+c,c=getchar();
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  s1[i]=read(),s2[i]=read();
	for(int i=1;i<=n;i++)
	  {
	  	len[i]=s1[i].size();
	  	int l=len[i]-1,r=0;
	  	for(int j=0;j<len[i];j++)
	  	  if(s1[i][j]!=s2[i][j])
	  	    {
	  	    	l=j;
	  	    	break;
			}
		for(int j=len[i]-1;j>=0;j--)
		  if(s1[i][j]!=s2[i][j])
		    {
		    	r=j;
		    	break;
			}
		z[i]=l;
		y[i]=r;
	  	for(int j=l;j<=r;j++)
	  	  h1[i]=(h1[i]*m1+s1[i][j])%mod,h2[i]=(h2[i]*m2+s2[i][j])%mod;
	  	mp[h1[i]][h2[i]].push_back(i);
	  	//cout<<h1[i]<<" "<<h2[i]<<endl;
	  }
	//cout<<"!"<<endl;
	while(q--)
	  {
	  	scanf("%s%s",t1,t2);
	  	ans=0;
	  	if(strlen(t1)!=strlen(t2))
	  	  {
	  	  	printf("0\n");
	  	  	continue;
		  }
	  	int l=n,r=0,sz=strlen(t1);
		long long hash1=0,hash2=0;
	  	for(int j=0;j<sz;j++)
	  	  if(t1[j]!=t2[j])
	  	    {
	  	    	l=j;
	  	    	break;
			}
		for(int j=sz-1;j>=0;j--)
		  if(t1[j]!=t2[j])
		    {
		    	r=j;
		    	break;
			}
	  	for(int j=l;j<=r;j++)
	  	  hash1=(hash1*m1+t1[j])%mod,hash2=(hash2*m2+t2[j])%mod;
		for(auto x:mp[hash1][hash2])
		  if(l>=z[x]&&r+len[x]<=sz+y[x])
		    {
		    	bool f=1;
		    	for(int j=0;j<z[x];j++)
		    	  if(t1[l-(z[x]-j)]!=s1[x][j])
		    	    {
		    	    	f=0;
		    	    	break;
					}
				if(!f)
				  continue;
				for(int j=y[x]+1;j<len[x];j++)
		    	  if(t1[r+j-y[x]]!=s1[x][j])
		    	    {
		    	    	f=0;
		    	    	break;
					}
				if(f)
				  ans++;
			}
		printf("%d\n",ans);
		//cout<<hash1<<" "<<hash2<<endl;
	  }
	return 0;
}/*1
2
10 9 8
4 0 0*/