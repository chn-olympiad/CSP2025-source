#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,z;
}e[1000500],lin[150000],chu[1000500];
int father[150000],c[15],a[15][50000],cnt;
long long ans = 1e18,sumc;
bool cmp(node a,node b){
	return a.z<b.z;
}
void _init(){
	for(int i = 1;i<=10500;i++){
		father[i] = i;
	}
	return;
}
int _find(int x){
	if(father[x]==x){
		return x;
	}
	father[x] = _find(father[x]);
	return father[x];
}
void merge(int a,int b){
	father[_find(a)] = _find(b);
	return;
}
long long kruskal1(){
	long long res = 0,o = 0;
	for(int i = 1;i<=m;i++){
		if(_find(e[i].u)!=_find(e[i].v)){
			merge(e[i].u,e[i].v);
			o++;
			lin[o].u = e[i].u;
			lin[o].v = e[i].v;
			lin[o].z = e[i].z;
			res+=e[i].z;
		}
	}
	return res;
}
long long kruskal2(){
	long long res = 0;
	
	for(int i = 1;i<=cnt;i++){
//			cout<<chu[i].u<<' '<<chu[i].v<<endl;
		if(_find(chu[i].u)!=_find(chu[i].v)){
			merge(chu[i].u,chu[i].v);
//			cout<<'&'<<endl;
			res+=chu[i].z;
		}
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].z);
	}
	_init();
	sort(e+1,e+m+1,cmp);
	ans = min(ans,kruskal1());
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
//		for(int i = 1;i<n;i++){
//			cout<<lin[i].u<<' '<<lin[i].v<<' '<<lin[i].z<<endl;
//		}
	for(int i = 0;i<(1<<k);i++){
		for(int i = 1;i<n;i++){
			chu[i].u = lin[i].u;
			chu[i].v = lin[i].v;
			chu[i].z = lin[i].z;
		}
		cnt = n-1;
		int ji = i;
		sumc = 0;
		for(int j = 1;j<=k;j++){
			if((ji&1)==1){
				for(int g = 1;g<=n;g++){
					cnt++;
					chu[cnt].u = g;
					chu[cnt].v = 10001+j;
					chu[cnt].z = a[j][g];
				}
				sumc+=c[j];
			}
			ji>>=1;
		}
		chu[cnt+1].u = 0;
		chu[cnt+1].v = 0;
		chu[cnt+1].z = 0;
//		cout<<endl;
		sort(chu+1,chu+cnt+1,cmp);
//		for(int i = 1;i<=cnt;i++){
//			cout<<chu[i].u<<' '<<chu[i].v<<' '<<chu[i].z<<endl;
//		}
		
		_init();
		ans = min(ans,kruskal2()+sumc);
	}
	cout<<ans;
	return 0;
}

