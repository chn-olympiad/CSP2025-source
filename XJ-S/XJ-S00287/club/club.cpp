#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N=1e3+5;
int n,ans;
struct node{
 int a,b,c;
};
node a[N];
void dfs(int x,int s1,int s2,int s3,int cnt)
{
 if(x==n+1)
 {
  ans=max(ans,cnt);
  return;
 }
 if(x>n||s1>n/2||s2>n/2||s3>n/2)
  return;
 if(s1<n/2)
  dfs(x+1,s1+1,s2,s3,cnt+a[x].a); 
 if(s2<n/2)
  dfs(x+1,s1,s2+1,s3,cnt+a[x].b); 
 if(s3<n/2)
  dfs(x+1,s1,s2,s3+1,cnt+a[x].c); 
}
signed main()
{
	freopen("club.in","r",stdin); 
    freopen("club.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
     ans=0;
     cin>>n;
     for(int i=1;i<=n;i++)
      cin>>a[i].a>>a[i].b>>a[i].c;
     dfs(1,0,0,0,0);
	 cout<<ans<<'\n';
	}
    return 0;
}
