#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
long long fa[N],n,m,k,sum=0;
long long lin[15][100005];
long long get(long long x){
	if(fa[x]==x)	return x;
	return fa[x]=get(fa[x]);
}
void merge(long long x,long long y){
	fa[get(y)]=get(x);
}
struct grap{
	long long st,ed,dat;
}a[N];
long long cmp(grap x,grap y){
	return x.dat<y.dat;
}
long long tot=0;
void add(long long u,long long v,long long z){
	a[++tot]={u,v,z};
}



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
	
	for(long long i=1,x,y,z;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	
	
	for(long long i=1,c;i<=k;i++){
		scanf("%lld",&c);
		for(long long j=1,z;j<=n;j++){
			scanf("%lld",&z);
			lin[i][j]=z;
		}
		for(long long j=1;j<n;j++){
			for(long long k=j+1;k<=n;k++){
				add(j,k,lin[i][j]+lin[i][k]+c);
				add(k,j,lin[i][j]+lin[i][k]+c);
			}
		}
	}
	
	sort(a+1,a+1+tot,cmp);
	
	for(long long i=1;i<=tot;i++){
		long long x=a[i].st,y=a[i].ed,z=a[i].dat;
		if(get(x)==get(y)){
			continue;
		}
		merge(x,y);
		sum+=z;
		
	}
	printf("%lld",sum);
	
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

5 4 1
1 3 1
1 4 2
3 2 6
3 5 9
5 1 1 1 999 1

5 4 1
1 2 2
2 3 50
3 4 70
4 5 100
100 3 3 3 3 3
*/