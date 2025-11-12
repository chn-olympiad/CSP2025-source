#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v;
	long long w;
};
int f[10025];
int t[10025];
long long c[15];
long long s[15];
bool use[15];
long long b[15];
bool operator<(node a,node b){
	long long aw=a.w,bw=b.w;
	if(a.u>n and !use[a.u-n]) aw+=c[a.u-n];
	if(a.v>n and !use[a.v-n]) aw+=c[a.v-n];
	if(b.u>n and !use[b.u-n]) bw+=c[b.u-n];
	if(b.v>n and !use[b.v-n]) bw+=c[b.v-n];
	return aw>bw;
}int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}bool check(int x,int y){
	return find(x)==find(y);
}void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(x==y) return;
	f[fx]=fy;
	t[fy]+=t[fx];
}priority_queue<node> q;
void change(){
	queue<node> p;
	while(!q.empty()){
		p.push(q.top());
		q.pop();
	}while(!p.empty()){
		q.push(p.front());
		p.pop();
	}
}long long h(){
	long long ans=0;
	while(!q.empty()){
		node p=q.top();
		q.pop();
		int u=p.u,v=p.v;
		long long w=p.w;
		if(check(u,v)) continue;
		join(u,v);
		if(u>n){
			if(!use[u-n]){
				ans+=c[u-n];
				use[u-n]=true;
				b[u-n]=w;
				change();
			}s[u-n]++;
		}else if(v>n){
			if(!use[v-n]){
				ans+=c[v-n];
				use[v-n]=true;
				b[v-n]=w;
				change();
			}s[v-n]++;
		}ans+=w;
		if(t[find(v)]==n){
			for(int i=1;i<=k;i++){
				if(s[i]==1) ans-=c[i]+b[i];
			}return ans;
		}
	}return 0;
}inline static int get(){
	char c=getchar();
	int s=0;
	while(c!=' '){
		s=s*10+c-'0';
		c=getchar();
	}return s;
}inline static long long tget(){
	char c=getchar();
	long long s=0;
	while(c>='0' and c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=n;i++) t[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		u=get(),v=get(),w=tget();
		q.push(node{u,v,w});
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;
			w=tget();
			q.push(node{n+i,j,w});
		}
	}cout<<h();
	return 0;
}
