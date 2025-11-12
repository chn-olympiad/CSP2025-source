#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+110;// 10ceng
LL cost;
int n,m,k;
struct edge{
	int a,b,w;
	bool operator < (const edge & rhs) const{
		return w < rhs.w;
	}
}e[N*10];
int idx;
int inf ;
int f[2*N];
void init(int n){
	for(int i = 1; i <= n; i++)
		f[i] = i;
	f[inf] = inf;	
}
int getf(int a){
	if(f[a] == a) return a;
	return f[a] = getf(a);
}
int cnt = 0;

void p(){
	for(int i = 1; i <= idx ; i++){
		cout << e[i].a <<" "<< e[i].b << " "<<e[i].w << endl;
	}
}
void krul(){
	
	sort(e + 1, e + 1 + idx);
//	p();
	for(int i = 1 ;i < m + k; i++){
		int v = e[i].a, u =e[i].b;
		if(f[u] != f[v]){
				f[v] = inf;
		f[u] = inf;
		cost += e[i].w;
		}
	
	
		
		
	}
	
}
int main(){
	
	freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	inf = n + k + k;
	for(int u,v,w,i = 1; i <= m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[++idx] ={u,v,w};
	}
	for(int c,a,i = 1; i <= k; i++){
		scanf("%d",&c);
		for(int j = 1; j <= n; j++){
			scanf("%d",&a);
			// 直接令改造费用为0 
			int u = i+n;// 将第i个乡镇改造 

		//	e[++idx] ={u,j,a};
		}
	}
	init(n+k);
	krul();
	printf("%lld",cost);
	
	
	return 0;
} 
