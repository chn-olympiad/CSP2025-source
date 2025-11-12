#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7+7;
const int maxn = 1e4+7;
int n,m,k,cnt,fa[maxn],sb[15][maxn],num;
long long ans;
struct hzh{
	int a,b;
	long long c;
} l[MAXN];
int find(int x){
	if(x!=fa[x]) x=fa[x];
	return fa[x];
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
	cnt++;
}
bool cmp(hzh x,hzh y){
	return x.c<y.c;
}
void addadd(int cnm){
	int nb=num+1;
	for(int wc=1;wc<=n-1;wc++){
		for(int md=wc+1;md<=n;md++){
			l[nb].a=wc;
			l[nb].b=md;
			l[nb].c=sb[cnm][wc]+sb[cnm][md];
			nb++;
		}
	}	
	ans+=sb[cnm][0];
	num=nb;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	num=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&sb[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&sb[i][j]);
		}
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=m;i++){
			if(l[i].c>=sb[j][l[i].a]+sb[j][l[i].b]+sb[j][0]){
				addadd(j);
				i=m;
			}
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(l+1,l+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(cnt==n-1){
			printf("%d",ans);
			return 0;
		};
		if(fa[l[i].a]!=fa[l[i].b]){
			ans+=l[i].c;
			add(l[i].a,l[i].b);
		}
	}
	return 0; 
}