/*
/\ /\
(OWO)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Way{
	int u,v;
	long long w;
}w[1000010];
long long c[20],a[20][10010];
int fa[10010];
int ans=0;
int flag=1;

void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
} 
int Find(int x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

bool cmp(Way x,Way y){
	return x.w<y.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,ww;
    	cin>>u>>v>>ww;
    	w[i].u=u,w[i].v=v,w[i].w=ww;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=0;
		}
	}

	if(k==0){
		init();
		sort(w+1,w+1+m,cmp);
		/*cout<<endl;
		for(int i=1;i<=m;i++){
			int u=w[i].u,v=w[i].v,ww=w[i].w;
			cout<<u<<' '<<v<<' '<<ww<<endl;
		}
		cout<<endl;*/
		int cnt=0,i=1;
		while(cnt<n-1 && i<=m){
			int u=w[i].u,v=w[i].v,ww=w[i].w;
			if(Find(u)==Find(v)){
				i++;
				continue;
			}else{
				Union(u,v);
				ans+=ww;
				cnt++;
				i++;
				//cout<<u<<' '<<v<<' '<<ans<<endl;
			}
		}
		cout<<ans;
	}else if(flag==1){
		cout<<0;
	} 
	
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
4 5 0
1 4 5 
1 3 3
3 2 4
3 4 2
1 4 3
*/
/*
4 5 2
1 4 5
1 3 3
3 2 4
3 4 2
1 4 3
0 0 0 0 0
0 0 0 0 0
*/
