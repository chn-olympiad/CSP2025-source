#include<bits/stdc++.h>
using namespace std;
const int N=5000010;
struct node{
	long long a,b,c;
}line[N];
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int cmp(node a,node b){
	return a.c<b.c;
}
long long cst[N];
map<long long,long long> a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&line[i].a,&line[i].b,&line[i].c);
	sort(line+1,line+1+m,cmp);
	long long ccnntt=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&cst[i]);
		ccnntt+=cst[i];
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[n+i][j]),ccnntt+=a[n+i][j];
	}
	if(ccnntt==0){
		long long cnt=0;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(line+1,line+1+m,cmp);
		for(int i=1;i<=m;i++){
			int a=line[i].a,b=line[i].b,c=line[i].c;
			if(find(a)!=find(b))
				cnt+=c,fa[find(a)]=find(b);
		}
		cout<<cnt;
	}
	else{
		long long ans=1e18;
		for(int now=0;now<(1<<k);now++){
			int m1=m;
			long long cnt=0;
			for(int i=1;i<=k;i++){
				if((now>>i)&1){
					cnt+=cst[i];
					for(int j=1;j<=n;j++)
						line[++m1].a=n+i,line[m1].b=j,line[m1].c=a[n+i][j];
				}
			}
			for(int i=1;i<=n+k;i++)
				fa[i]=i;
			sort(line+1,line+1+m1,cmp);
			for(int i=1;i<=m1;i++){
				int a=line[i].a,b=line[i].b,c=line[i].c;
				if(find(a)!=find(b))
					cnt+=c,fa[find(a)]=find(b);
			}
			ans=min(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
