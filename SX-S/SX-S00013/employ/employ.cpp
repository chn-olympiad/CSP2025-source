#include<bits/stdc++.h>
using namespace std;
int b[100010],c[510],d[510];
int ans=0;
long long n,m;
void dfs(int t,int r,int sb)
{
	if(t==n+1)
	{
        if(r>=m)
        {
        	ans++;
        	ans=ans%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
      if(d[i]==0)
      {
      	d[i]++;
      	if(sb>=c[i]||b[t]==0) dfs(t+1,r,sb+1);
      	else dfs(t+1,r+1,sb);
      	d[i]--;
	  }
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    char a[510];
    cin>>a;
    int sl;
	sl=strlen(a);
    for(int i=1;i<=sl;i++)
    {
    	b[i]=a[i-1]-'0';
	}
    for(int i=1;i<=n;i++)
    {
     cin>>c[i];
	}
    dfs(1,0,0);
    cout<<ans;
	return 0;
}