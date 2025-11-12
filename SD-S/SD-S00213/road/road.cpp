#include<bits/stdc++.h>
using namespace std;
#define go(i,l,r) for(int (i)=(l);(i)<=(r);++(i))

#define ll long long
#define int ll

int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return w*x;
}

const int N=1e4+20;
const int M=1e4+10;
int n,m,k,c[11];
struct node{
	int to,val;
	bool operator < (const node& x) const {
		return val>x.val;
	}
};
vector<node> g[N];

int stp,res,ans;
int abn[13],vis[N],ed;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	go(i,1,m){
		int a,b,c;
		a=read(),b=read(),c=read();
		g[a].push_back( (node){b,c} );
		g[b].push_back( (node){a,c} );
	}
	
	go(i,1,k){
		c[i]=read();
		go(j,1,n){
			int w=read();
			g[n+i].push_back( (node){j,w} );
			g[j].push_back( (node){n+i,w} );
		}
	}
	
	stp=(1<<(k+1))-1;
	stp--;
	ans=0x3f3f3f3f;
	
	go(t,0,stp){
		memset(vis,0,sizeof vis);
		res=0,ed=0;
		int fl=0;
		go(i,1,k)
			if(t&(1<<(i-1))){
				if(c[i]>ans) abn[i]=1;
				if(abn[i]==1){
					fl=1;
					break;
				}
				res+=c[i];
			}
		if(fl) continue;
		priority_queue<node> pq;
		vis[1]=1;
		for(auto e:g[1]){
			if(e.to>n&&(t&(1<<(e.to-n-1)))==0) continue;
			pq.push(e);
		}
		
		while(pq.size()&&ed<n){
			int v=pq.top().to,w=pq.top().val;
			pq.pop();
			if(vis[v]) continue;
			
			vis[v]=1;
			if(v<=n) ed++;
			res+=w;
			for(auto e:g[v]){
				if(vis[e.to]) continue;
				if(e.to>n&&(t&(1<<(e.to-n-1)))==0) continue;
				pq.push(e);
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

