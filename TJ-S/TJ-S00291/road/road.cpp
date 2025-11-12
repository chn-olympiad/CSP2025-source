#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct Edge{
	int fr,to,va,p;
	bool operator<(const Edge &a)const{
		return a.va<va;
	}
}e[4000055];
int cun[20][20000];
int fz[20];
int n,m,k,cnt=0,cnt1=0;
int cnt2=0;
Edge e1[500000];
void add_e(int u,int v,int w){
	cnt++;
	e[cnt]={u,v,w,cnt};
	return;
}
void add_e1(int u,int v,int w){
	cnt2++;
	e1[cnt2]={u,v,w,cnt};
	return;
}
priority_queue<Edge> q;
priority_queue<Edge> q1;
queue<Edge> q2;
int fa[20000];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int kruskal1(int x){
	for(int i=1;i<=x;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		q.push(e[i]);
	}
	int ct=0,res=0;
	//cout<<"$"<<x<<"\n";
	while(ct<(x-1)){
		Edge x=q.top();;
		q.pop();
		int u=x.fr,v=x.to;
	//	cout<<u<<" "<<v<<" "<<ct<<"\n";
	//	cout<<find(u)<<" "<<find(v)<<"\n";
		if(find(u)!=find(v)){
			ct++;
			res+=x.va;
			fa[fa[u]]=v;
		}
	}
	return res;
}
int kruskal(int x){
	for(int i=1;i<=x;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt2;i++){
		q1.push(e1[i]);
	}
	int ct=0,res=0;
	//cout<<"$"<<x<<"\n";
	while(ct<(x-1)){
		Edge x,y;
		if(q.empty()){
		//	cout<<"&";
			x=q1.top();
			q1.pop();
		}else if(q1.empty()){
		//	cout<<"^";
			x=q.top();
		//	cout<<x.p<<"\n";
			q.pop();
			q2.push(x);
		//	cout<<y.p<<"\n";
		}else{
			x=q.top();
			y=q1.top();
		//	cout<<":"<<x.va<<" "<<y.va<<"\n"; 
			if(x.va<=y.va) {
				q.pop();
				q2.push(x);
			}else {
				x=y;
				q1.pop();
			}
		}
	//	cout<<"kkk";
		int u=x.fr,v=x.to;
		
		if(find(u)!=find(v)){
			ct++;
			res+=x.va;
			fa[fa[u]]=fa[v];
		}
	//	cout<<u<<" "<<v<<" "<<res<<"\n";
	}
	return res;
}
void add_cun(int x){
	for(int i=1;i<=n;i++){
		add_e1(n+x,i,cun[x][i]);
	}
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_e(u,v,w);
	}
	int fl=1;
	for(int i=1;i<=k;i++){
		cin>>fz[i];
		int fl1=0;
		for(int j=1;j<=n;j++){
			cin>>cun[i][j];
			if(cun[i][j]==0) fl1=1;
		}
		if(fl1==0){
			fl=0;
		}
	}
	
	for(int i=1;i<=k;i++){
		if(fz[i]!=0) fl=0;
	}
	if(fl!=1){
		
		for(int i=1;i<=cnt;i++){
			q.push(e[i]);
		}
		cnt1=cnt;
		int ans=100000000000000000;
		int kkk=pow(2,k)-1; 
		for(int i=0;i<=kkk;i++){
			
			int sum=0;
			cnt2=0;
			int ct1=0,ct=0;
			int zt=i;
			while(zt>0){
				ct++;
				if(zt&1){
					sum+=fz[ct];
				//	cout<<"%";
					add_cun(ct);
					ct1++;
				}
				zt>>=1;
			}
			ans=min(ans,kruskal(n+ct1)+sum);
		//	cout<<ans<<"\n";
			while(!q2.empty()){
			//	cout<<"!";
				Edge czh=q2.front();
				q2.pop();
				q.push(czh);
			} 
		}
		cout<<ans<<"\n";
	}else{
		for(int i=1;i<=k;i++){
			
			for(int j=1;j<=n;j++){
				
				add_e(n+i,j,cun[i][j]);
			}
		}
		int ans=kruskal1(n+k);
		cout<<ans<<"\n";
	}
	
	return 0;
}

