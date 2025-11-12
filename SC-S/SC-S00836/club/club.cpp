#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n,f_a,f_b,vis[N],ans;
struct Node{
	int w,id;
}a[N],b[N],c[N];
bool cmp(Node u,Node v){
	return u.w<v.w;
}
void init(){
	f_a=1,f_b=1,ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].w,&b[i].w,&c[i].w);
		a[i].id=i;
		b[i].id=i;
		c[i].id=i;
		if(c[i].w!=0){
			f_a=0;
			f_b=0;
		}
		else if(b[i].w!=0){
			f_a=0;
		}
	}
}
void dfs(int x,int sum,int o,int p,int q){
	if(x==n+1){
		if(o<=n/2&&p<=n/2&&q<=n/2){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(x+1,sum+a[x].w,o+1,p,q);
	dfs(x+1,sum+b[x].w,o,p+1,q);
	dfs(x+1,sum+c[x].w,o,p,q+1);
	dfs(x+1,sum,o,p,q);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		init();
		if(f_a){
			sort(a+1,a+n+1,cmp);
			for(int i=n;i>=n/2;i--){
				ans+=a[i].w;
			}
			printf("%lld\n",ans);
		}
		else if(f_b){
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			memset(vis,0,sizeof(vis));
			priority_queue<int,vector<int>,greater<int> >q;
			while(!q.empty()) q.pop();
			int cnt=0,cnt1=0;
			for(int i=n;i>=1;i--){
				if(a[i].id==b[i].id&&!vis[a[i].id]){
					vis[a[i].id]=1;
					if(a[i].w>b[i].w&&cnt<n/2){
						ans+=a[i].w;
						q.push(a[i].w);
						cnt++;
					}
					else if(a[i].w<b[i].w&&cnt1<n/2){
						ans+=b[i].w;
						q.push(b[i].w);
						cnt1++;
					}
					else if(a[i].w==b[i].w&&cnt1<n/2&&cnt<n){
						q.push(a[i].w);
						ans+=a[i].w;
					}
					continue;
				}
				if(!vis[a[i].id]&&cnt<n/2){
					ans+=a[i].w;
					q.push(a[i].w);
					cnt++;
					vis[a[i].id]=1;
				}
				if(!vis[b[i].id]&&cnt1<n/2){
					ans+=b[i].w;
					q.push(b[i].w);
					cnt1++;
					vis[b[i].id]=1;
				}
			}
			while(q.size()>n&&!q.empty()){
				ans-=q.top();
				q.pop();
			}
			printf("%lld\n",ans);
		}
		else{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}