#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int tw[20005],bwa[15][20005];
vector<pair<int,int> >bw[20005];
//LONG LONG!!!!!!!!!
long long ans;


//bcj
int fa[20005];

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void hb(int x,int y){
	fa[find(x)]=find(y);
}
//tu
int tot=0;
vector<int>v[20005];
struct node{
	int u,v,w;
}a[2000005],b[2000005];

bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	//init
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		/*hb(a[i].u,a[i].v);
		for(int i=1;i<=n;i++){
			cout<<find(i)<<" ";
		}
		cout<<"\n";*/
	}
	int fla=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&tw[i]);
		if(tw[i]!=0){
			fla=1;
		}
		for(int j=1;j<=n;j++){
			int cc;
			scanf("%d",&cc);
			bwa[i][j]=cc;
			/*pair<int,int>ccc;
			ccc={j,cc};
			bw[i].push_back(ccc);*/
		}
	}	
	//min tree ver
	if(fla==0&&k!=0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[++m].u=i+n;
				a[m].v=j;
				a[m].w=bwa[i][j];
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			/*	for(int i=1;i<=n;i++){
				cout<<find(i)<<" ";
			}
			cout<<"\n";*/
			if(find(a[i].u)==find(a[i].v)){
				//continue;
			}
			else{
				hb(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
		printf("%lld",ans);
	}
	else{
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			/*	for(int i=1;i<=n;i++){
			cout<<find(i)<<" ";
			}
			cout<<"\n";*/
			if(find(a[i].u)==find(a[i].v)){
				//continue;
			}
			else{
				hb(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
		printf("%lld",ans);
	}
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


4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
