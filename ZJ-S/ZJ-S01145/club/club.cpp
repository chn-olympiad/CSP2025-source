#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,cnt[3];
ll d[3][N];
bool vis[N];
struct node{
	ll id,a;
}a[N],b[N],c[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		cin>>n;
		ll ans=0;
		for (int i=1;i<=n;i++){
			cin>>d[0][i]>>d[1][i]>>d[2][i];
			a[i]={i,d[0][i]};
			b[i]={i,d[1][i]};
			c[i]={i,d[2][i]};
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		if(n<=2){
			cout<<max({d[0][1]+d[1][2],d[0][1]+d[2][2],d[1][1]+d[0][2],d[1][1]+d[2][2],d[2][1]+d[0][2],d[2][1]+d[1][2]});
			break;
		}
		for (int u=1,v=1,w=1,i=1;i<=n;i++){
			if(max({a[u].a,b[v].a,c[w].a})==a[u].a && cnt[0]<n/2){
				if(!vis[a[u].id]){
					vis[a[u].id]=true;
					ans+=a[u].a;
					cnt[0]++;
				}
				u++;
			}
			if(max({a[u].a,b[v].a,c[w].a})==b[v].a && cnt[1]<n/2){
				if(!vis[b[v].id]){
					vis[b[v].id]=true;
					ans+=b[v].a;
					cnt[1]++;
				}
				v++;
			}
			if(max({a[u].a,b[v].a,c[w].a})==c[w].a && cnt[2]<n/2){
				if(!vis[c[w].id]){
					vis[c[w].id]=true;
					ans+=c[w].a;
					cnt[2]++;
				}
				w++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}