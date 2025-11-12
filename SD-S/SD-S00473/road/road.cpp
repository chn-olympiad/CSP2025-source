#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m,k;
int ans;
int f[N];
struct node{
	int a,b,c;
}p[N];
bool cmp(node x,node y){
	if(x.c<y.c){
		return x.c<y.c;
	}
	return x.a<y.a;
}
int find(int a){
	if(a==f[a]) return a;
	return f[a]=find(f[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=m;i++){
			int fa=find(p[i].a);
			int fb=find(p[i].b);
			if(fa!=fb){
				f[fa]=fb;
				ans+=p[i].c;
			}
		}
		printf("%d",ans);
	}
	
	
	
	
	
	
	
	
	return 0;
}
