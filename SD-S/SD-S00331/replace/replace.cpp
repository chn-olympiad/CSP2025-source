#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q;
string s1[N],s2[N]; 
bool pre[N],suf[N]; 
struct node{
	int l,r,x;
}a[N],b[N];
ll ans=0;
void solve1()
{
	ans=0;
	string t1,t2;
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
	  cout<<"0\n";
	  return;	
	}
	for(int i=1;i<=t1.size();i++)  pre[i]=suf[i]=0;
	pre[0]=1;
	for(int i=1;i<=t1.size();i++)
	  if(pre[i-1]&&t1[i-1]==t2[i-1])
	    pre[i]=1;
	suf[t1.size()+1]=1;
	for(int i=t1.size();i>=1;i--)  
	  if(suf[i+1]&&t1[i-1]==t2[i-1])
	    suf[i]=1;
	for(int j=1;j<=n;j++)
	{
	  if(s1[j].size()>t1.size())  continue;
	  for(int i=0;i<t1.size()-s1[j].size()+1;i++)  
	  {
	  	bool flag=1;
	    for(int k=0;k<s1[j].size();k++)
	      if(s1[j][k]!=t1[i+k]||s2[j][k]!=t2[i+k])
	      {
	        flag=0;
			break;
		  }
		if(flag&&pre[i]&&suf[i+s1[j].size()+1])  ans++;
	  }
	}
	cout<<ans<<"\n";
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
	  int id1=0,id2=0;
	  for(int j=0;j<s1[i].size();j++)
	    if(s1[i][j]=='b')
	      id1=j;
	  for(int j=0;j<s2[i].size();j++)
	    if(s2[i][j]=='b')
	      id2=j;
	  a[i]={id1,(int)s1[i].size()-id1-1,id1};
	  b[i]={id2,(int)s2[i].size()-id2-1,id2};
	}
	string t1,t2;
	while(q--)
	{
	  ans=0;
	  int id1=0,id2=0,ll=0,rr=0,lll=0,rrr=0;
	  cin>>t1>>t2;
	  if(t1.size()!=t2.size()){
	    cout<<"0\n";
	    continue;	
	  }
	  for(int j=0;j<t1.size();j++)
	    if(t1[j]=='b')
	      id1=j;
	  for(int j=0;j<t2.size();j++)
	    if(t2[j]=='b')
	      id2=j;
	  ll=id1,rr=t1.size()-id1-1;
	  lll=id2,rrr=t2.size()-id2-1;
	  for(int i=1;i<=n;i++)
	  {
	  	if(id1-id2!=a[i].x-b[i].x)  continue;
	  	if(a[i].l<=ll&&a[i].r<=rr&&b[i].l<=lll&&b[i].r<=rrr)  ans++;
	  }
	  cout<<ans<<"\n";
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)  cin>>s1[i]>>s2[i]; 
	if(n<=500&&q<=500)
	{
	  while(q--)  solve1();	
	  return 0;
	}
	solve2();
	return 0;
}

