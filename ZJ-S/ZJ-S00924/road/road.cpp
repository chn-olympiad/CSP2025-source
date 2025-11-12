#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,f[1000440],q;
long long s;
struct node{
	int u,v,w;
}e[1000555],o[1000555];
int fa(int x){
	if(f[x]==x)return x;
	else return f[x]=fa(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	if(k==0){
		//1
		for(int i=1;i<=n+k+1;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			e[i].u=u,e[i].v=v,e[i].w=w;
			
		}
		
		for(int i=1;i<=k;i++){
			cin>>t;
			for(int i=1;i<=n;i++){
				cin>>w;
			}
		}
		n+=k;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(fa(u)!=fa(v)){
				s+=w;
				f[fa(u)]=fa(v);
			}
		}cout<<s;
		//2
	}
	else{
		
	
		for(int i=1;i<=n+k+1;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			e[i].u=u,e[i].v=v,e[i].w=w;
			
		}
		//bakshizuobian
		for(int i=1;i<=k;i++){
			cin>>t;
			q=0;
			for(int i=1;i<=n;i++){
				cin>>w;
				v=i;
				u=q;
				//cout<<u<<" "<<v<<" "<<w<<endl;
				o[++q].u=u,o[q].w =w,o[q].v=v;
			}//cout<<"%%"<<endl;
			for(register int i=1;i<=n;i++){
				for(register int j=i+1;j<=n;j++){
					u=o[i].v ,v=o[j].v,w=o[i].w+o[j].w ;
					//cout<<u<<" "<<v<<" "<<w<<endl;
					e[++m].u=u,e[m].v=v,e[m].w=w;
				}
			}
		}
		
		n+=k;
		sort(e+1,e+m+1,cmp);
		long long h=0;
		for(int i=1;i<=m;i++){
			//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(fa(u)!=fa(v)){
				s+=w;
				f[fa(u)]=fa(v);
				h++;
			}if(h>=n)break;
		}cout<<s;
		
	}
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
