#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+20;
ll n,m,k,mn[20],cm[20],vis[20],p[N][20],co[20],cnt,head[N],ans;
queue<int> q;
struct node{
	int nxt,to,w;
}e[N*2]; 
struct nod{
	int u,v,w;
}a[N*2]; 
void add(int x,int y,int z){
	e[++cnt].nxt=head[x];
	e[cnt].to=y;
	e[cnt].w=z;
	head[x]=cnt;
}
bool cmp(nod x,nod y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cm[i]=mn[i]=1000000000;
		cin>>co[i]; 
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			if(mn[i]>p[i][j]){
				cm[i]=mn[i];
				mn[i]=p[i][j];
			}
			else{
				if(cm[i]>p[i][j]){
					cm[i]=p[i][j];
				}
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int op=1;op<=m;op++){
		int t=a[op].v; 
		for(int i=head[a[op].u];i;i=e[i].nxt){
			if(e[i].w!=-1){
				if(e[i].to!=t){
					q.push(e[i].to);
				}	
			}
		}
		bool f=0;
		int fr=a[op].u;
		while(!q.empty()){
			int v=q.front();
			q.pop();
			for(int i=head[v];i;i=e[i].nxt){
				if(e[i].w!=-1&&e[i].to!=fr){
					fr=e[i].to;
					if(e[i].to!=t){
						q.push(e[i].to);
					}
					else{
						f=1;break;
					}	
				}
			}
			if(f){
				break;
			}
		}
		if(f){
			a[op].w=-1;
			for(int i=head[a[op].u];i;i=e[i].nxt){
				if(e[i].to==a[op].v){
					e[i].w=-1;
				}
			}
			for(int i=head[a[op].v];i;i=e[i].nxt){
				if(e[i].to==a[op].u){
					e[i].w=-1;
				}
			}
		}
		else{
			int an=1000000000,now=0;
			t=a[op].u;
			for(int j=1;j<=k;j++){
				int sum=0;
				if(mn[j]==p[t][j]){
					sum=cm[j]; 
				}
				else{
					sum=mn[j];
				}
				sum+=p[j][t];
				if(!vis[j]){
					sum+=co[j];
				}
				if(an>sum){
					an=sum,now=j;
				}
			}
			if(a[op].w>=an){
				vis[now]=1;
				ans+=an;
				a[op].w=-1;
				for(int i=head[a[op].u];i;i=e[i].nxt){
					if(e[i].to==a[op].v){
						e[i].w=-1;
					}
				}
				for(int i=head[a[op].v];i;i=e[i].nxt){
					if(e[i].to==a[op].u){
						e[i].w=-1;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].w!=-1){
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
