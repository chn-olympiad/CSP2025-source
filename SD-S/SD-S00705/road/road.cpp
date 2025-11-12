#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
int n,m,k;
struct node{
	int from,to,val;
}v[2*M];
int fa[N*2];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int Find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=Find(fa[x]);
}
int paid[20];
bool flag[15];
void kruskal(int m1){
	int cnt=0,sum=0,cheng;
	for(int i=1;i<=m1;i++){
		int r=v[i].from,t=v[i].to;
		int far=Find(r),fat=Find(t);
		if(far==fat) continue;
		if(far>n){
			if(flag[far-n]==0){
				cheng++;
				flag[far-n]=1;
				sum+=v[i].val;
			}else{
				sum+=v[i].val-paid[far-n];
			}
		}else{
			sum+=v[i].val; 
		}
		//cout<<v[i].from<<" "<<v[i].to<<" "<<v[i].val<<"\n";
		cnt++;
		if(cnt==(n+cheng)-1){
			break;
		}
	}
	cout<<sum;
}
bool cmp(node a,node b){
	if(a.val==b.val) return a.from<b.from;
	return a.val<b.val;
}
signed main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init(n*2);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&v[i].from,&v[i].to,&v[i].val);
	}
	int cnt=m;
	int FLAG=0; 
	for(int i=1;i<=k;i++){
		cin>>paid[i];
		if(paid[i]) FLAG=1;
		for(int j=1;j<=n;j++){
			int cp;
			cin>>cp;
			if(cp) FLAG=1;
			cp+=paid[i];
			v[++cnt].from=n+i,v[cnt].to=j,v[cnt].val=cp;
		}
	}
	if(!FLAG){
		cout<<0;
		return 0;
	}
	sort(v+1,v+1+cnt,cmp);
	kruskal(cnt);
	return 0;
}

