#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int x,y,z,ans,vis[N],sum[5];
struct node{
	int id;
	int x;
	int nu;
	int q;
}f[N*3+10];
bool cmp(node x,node y){
	if(x.q==y.q) return x.x>y.x;
	return x.q>y.q;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		memset(f,0,sizeof(f));
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			f[i*3-2].id=i;
			f[i*3-1].id=i;
			f[i*3].id=i;
			f[i*3-2].x=a;
			f[i*3-1].x=b;
			f[i*3].x=c;
			f[i*3-2].nu=1;
			f[i*3-1].nu=2;
			f[i*3].nu=3;
			if(a>=max(b,c)) f[i*3-2].q=a-max(b,c);
			if(b>=max(a,c)) f[i*3-1].q=b-max(a,c);
			if(c>=max(a,b)) f[i*3].q=c-max(a,b);
		}
		sort(f+1,f+1+n*3,cmp);
		for(int i=1;i<=n*3;i++){
			if(!vis[f[i].id] && sum[f[i].nu]<n/2){
				ans+=f[i].x;
				vis[f[i].id]=1;
				sum[f[i].nu]++;
				//cout<<f[i].nu<<" "<<sum[f[i].nu]<<endl;
			}
		}
		cout<<ans<<endl;
		
	}
}
