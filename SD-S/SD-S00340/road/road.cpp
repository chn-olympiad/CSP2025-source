#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct Bian{
	int x,y;
	int v;
	friend bool operator <(Bian c,Bian d){
		return c.v>d.v;
	}
}a[M];
int n,m,k;
long long ans;
priority_queue<Bian> Q;
int F[N];
int Nv[N];
int V[N];
struct Cun{
	int w;
	int Lv[N];
}C[20];
struct Tu{
	int bian;
	int Next;
}Edge[M*2];
int Head[N],tot=-1;
void Lian(int x,int y){
	Edge[++tot].bian=y;
	Edge[tot].Next=Head[x];
	Head[x]=tot;
}
void init(){
	for(int i=1;i<=n;i++){
		F[i]=i;
	} 
}
int Find(int x){
	if(F[x]==x)return x;
	return F[x]=Find(F[x]);
}
void ADD(int x,int y){
	F[Find(x)]=Find(y);
	return ;
}
void Push(int x){
	for(int i=Head[x];i!=-1;i=Edge[i].Next){
		Q.push(a[Edge[i].bian]); 
	}
}
void Solve(){
	init();
	int ct=0;
	Push(1);
	while(ct<n-1){
		Bian the=Q.top();
		Q.pop();
		if(Find(the.x)!=Find(the.y)){
			if(Find(the.x)==1){
				V[the.y]=the.v;
				ADD(the.y,the.x);
				Push(the.y);
			}
			else{
				V[the.x]=the.v;
				ADD(the.x,the.y);
				Push(the.x);
			}
			ct++;
			ans+=the.v;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(Head,-1,sizeof(Head));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		Lian(x,i);
		Lian(y,i);
		a[i].x=x;
		a[i].y=y;
		cin>>a[i].v;
	}
	for(int i=1;i<=k;i++){
		cin>>C[i].w;
		for(int j=1;j<=n;j++){
			cin>>C[i].Lv[j];
		}
	}
	Solve();
	for(int i=0;i<=(1<<k)-1;i++){
		long long num=ans;
		for(int j=1;j<=n;j++){
			Nv[j]=V[j];
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				num=num+C[j].w;
				num=num+C[j].Lv[1];
				for(int g=2;g<=n;g++){
					if(Nv[g]>C[j].Lv[g]){
						num=num-Nv[g]+C[j].Lv[g];
						Nv[g]=C[j].Lv[g];
					}
				}
			}
		}
		ans=min(ans,num);
	}
	cout<<ans<<endl;
	return 0;
} 


