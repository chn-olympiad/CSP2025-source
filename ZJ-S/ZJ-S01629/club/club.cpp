#include<bits/stdc++.h>
#define int long long
using namespace std;
bool h1;
const int N=1e5+2;
int n,ans;
int a[N][4];
int p[N];
bool h2;
void dfs(int sum,int k,int aa,int bb,int cc)
{
 	if(k>2&&(((max(aa,max(bb,cc))>(k-1)/2)&&(k&1))||((max(aa,max(bb,cc))>(k-1)/2+1)&&!(k&1)))) return;
 	if(k>n){ans=max(ans,sum);return;}
	dfs(sum+a[k][3],k+1,aa,bb,cc+1);
	dfs(sum+a[k][2],k+1,aa,bb+1,cc);
	dfs(sum+a[k][1],k+1,aa+1,bb,cc);
}
signed main()
{
//	printf("%fMB",abs(&h1-&h2)/1024.0/1024.0);       
	freopen("club.in","r",stdin);    
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(p,0,sizeof p);
		cin>>n;
		ans=0;
		for(register int i=1;i<=n;++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(0,1,0,0,0);
		cout<<ans<<"\n"; 
    }
}
