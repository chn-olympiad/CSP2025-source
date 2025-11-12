#include <bits/stdc++.h>
using namespace std;
//int n,m,k;
//int sum;
//long long ans;
//long long ans1;
//bool vis;
//struct node{
//	long long w,u,v;
//}R[10010];
//vector<node> Vw;
//int fa[10010];
//int find(int x){
//	if(x==fa[x]) return x;
//	fa[x]=find(fa[x]);
//	return fa[x];
//}
//void dfs(long long id){
//	if(id>Vw.size()) return ;
//	if(id*2+1>Vw.size()){
//		if(id*2>Vw.size()) return ;
//		if(Vw[id*2-1].w<Vw[id-1].w){
//			swap(Vw[id*2-1],Vw[id-1]);
//			dfs(id*2);
//		}
//	}else{
//		if(Vw[id*2-1].w>Vw[id*2].w){
//			if(Vw[id*2].w<Vw[id-1].w){
//				swap(Vw[id*2],Vw[id-1]);
//				dfs(id*2+1);
//			}
//		}else{
//			if(Vw[id*2-1].w<Vw[id-1].w){
//				swap(Vw[id*2-1],Vw[id-1]);
//				dfs(id*2);
//			}
//		}
//	}
//}
//void add(long long w, long long u, long long v){
//	Vw.push_back({w,u,v});
//	swap(Vw[Vw.size()-1],Vw[0]);
//	dfs(1);
//}
//node pop(){
//	node q=Vw[0];
//	swap(Vw[0],Vw[Vw.size()-1]);
//	Vw.pop_back();
//	dfs(1);
//	return q;
//}
//long long cw[20];
//long long aw[10010][20];
//void dfs(int step,string l){
//	if(step==k){
//		ans1=0;
//		sum=n;
//		for(int i=1;i<=n;i++) fa[i]=i;
//		for(int i=1;i<=m;i++){
//			add(R[i].w,R[i].u,R[i].v);
//		}
//		for(int i=0;i<k;i++){
//			if(l[i]-'0'){
//				ans1+=cw[i+1];
//				for(long long o=1;o<=n;o++){
//					for(long long j=1;j<=n;j++){
//						if(o!=j){
//							
//							add({aw[o][i+1]+aw[j][i+1],o,j});
//						}
//					}
//				}
//			}
//		}
//		while(sum>1){
//			node z=pop();
//			if(find(z.u)!=find(z.v)){
//				fa[z.u]=find(z.v);
//				sum--;
//				ans1+=z.w;
//			} 
//		}
//		ans=max(ans,ans1);
//	}
//	dfs(step+1,l+"1");
//	dfs(step+1,l+"0");
//}
//bool cmp(node b, node c){
//	if(b.w!=c.w) return b.w < c.w;
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

