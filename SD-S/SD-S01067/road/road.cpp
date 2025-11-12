#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct Node{
	int u,v;
	ll w;
} a[2145140];
struct N{
	int k;
	int c[2145];
} b[14];
/*struct OP{
	int u,v;
} op;*/
int st[14],stt[114514];
ll ans=1e18,res,cnt;
priority_queue<pair<ll,int> > q;
int f[2145];

inline int find(int x){
	if(f[x]!=x)
	  return f[x]=find(f[x]); 
  return x;
}

void kr(){
	
	for(int i=1;i<=n+k;i++)
	  f[i]=i;
	for(int i=1;i<=m+cnt;i++){
		//op={a[i].u,a[i].v};
		//cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<'\n';
		q.push(make_pair(-a[i].w,i));
	}
	//cout<<q.top().first<<' ';  
	  
	while(q.size()){
		int x=a[q.top().second].u;
		int y=a[q.top().second].v;
		ll op=-q.top().first;
		//cout<<op<<' ';
		q.pop();//cout<<x<<' '<<y<<'\n';
		//cout<<x<<' ';
		if(find(f[x])==find(f[y]))
		  continue;
		//cout<<x<<' '<<y<<' '<<op<<'\n';
		f[y]=f[x];
		res+=op;  
		
	}  /*cout<<'\n';
	for(int i=1;i<=n+k;i++)
	  cout<<find(f[i])<<' ';
	    cout<<'\n';
	cout<<res<<'\n';*/
	ans=min(ans,res);
}

void dfs(int x){
	if(x>k){
	  res=0;	
		cnt=0;
		for(int i=1;i<=k;i++){
			if(!st[i]){
				//cout<<i<<"|";
				res+=b[i].k;
				for(int j=1;j<=n;j++){
					cnt++;
					a[m+cnt]={n+i,j,b[i].c[j]};
				}
			}  
		}
		
		kr();
			
		return ;	 
	}
	
	st[x]=1;
	dfs(x+1);
	st[x]=0;
	dfs(x+1);
}

int main(){
	freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	for(int i=1;i<=k;i++){
		cin>>b[i].k;
		for(int j=1;j<=n;j++)
		  cin>>b[i].c[j];
	}

	dfs(1);
	
	cout<<ans;
	
	return 0;
}

