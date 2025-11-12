#include<bits/stdc++.h>
using namespace std;
struct node {
	int u,v,w=1e9;
} city[1000005];
int fa[100005];
int coroad[15][15];
int cobuild[15],cofa[15];
int n,m,k;
bool cmp(node x,node y) {
	return x.w<y.w;
}
int check1() {
	for(int i=1; i<=n; i++) {
		if(fa[i]!=1) {
			return 1;
		} else {
			return 0;
		}
	}
}
int check2(int x,int y) {
	if(fa[x]==fa[y]) {
		return 1;
	} else {
		return 0;
	}
}
int sett(int x,int f) {
	for(int i=1; i<=n; i++) {
		if(fa[i]==fa[x]) {
			fa[i]=f;
		}
	}
}
int main() {
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>city[i].u>>city[i].v;
		int x;
		cin>>x;
		city[i].w=min(city[i].w,x);
		city[i+m].u=city[i].v;
		city[i+m].v=city[i].u;
		city[i+m].w=city[i].w;
	}
	int sizee=2*m;
	for(int i=1; i<=k; i++) {
		cin>>cobuild[i];
		for(int j=1; j<=n; j++) {
			cin>>coroad[i][j];
			fa[j]=j;
			cofa[j]=-1;
		}
	}
	for(int q=1; q<=k; q++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				sizee++;
				city[sizee].u=i;
				city[sizee].v=j;
				city[sizee].w=coroad[q][i]+coroad[q][j]+cobuild[q];
			}
		}
	}
	sort(city+1,city+1+sizee,cmp);
	int now=1;
	long long ans=0;
	while(check1()==0) {
		if(check2(city[now].u,city[now].v)==1) {
			now++;
			continue;
		}
		if(now>sizee){
			break;
		}
		int minn=1e9,flag;
		for(int i=1; i<=k; i++) {
			if(cobuild!=0) {
				minn=min(minn,coroad[i][city[now].u]+coroad[i][city[now].v]+cobuild[i]);
				if(minn==coroad[i][city[now].u]+coroad[i][city[now].v]+cobuild[i]) {
					flag=i;
				}
			}

		}
		if(minn<=city[now].w) {
			ans+=minn;
			int father=min(fa[city[now].u],fa[city[now].v]);
			cofa[flag]=father;
			cobuild[flag]=0;
			sett(city[now].u,father);
			sett(city[now].v,father);
			now=1;
			for(int i=1; i<=n; i++) {
				sizee++;
				city[sizee].u=cofa[flag];
				city[sizee].v=i;
				city[sizee].w=coroad[i][cofa[flag]];
				sizee++;
				city[sizee].u=i;
				city[sizee].v=cofa[flag];
				city[sizee].w=coroad[i][cofa[flag]];
			}
			sort(city+1,city+1+sizee,cmp);
		} else {
			ans+=city[now].w;
			int father=min(fa[city[now].u],fa[city[now].v]);
			sett(city[now].u,father);
			sett(city[now].v,father);
			now++;
		}
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
