#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
long long n,m,k,fa[N],b[N],p,cnt,minn=LLONG_MAX;
struct T{
	long long n;
	long long a[N];
}v[15];
struct E{
	long long x,y,z;
}t[M*10],t2[M*10];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(E a,E b){
	return a.z<b.z;
}
long long check(){
	for(int i=1;i<=n;i++) fa[i]=i;
	cnt=0;
	for(int i=1;i<=m;i++){
		t2[i]={t[i].x,t[i].y,t[i].z};
	}
	cnt=m;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=n;j++){
			t2[++cnt]={b[i]+n,j,v[b[i]].a[j]};
		}
	}
	sort(t2+1,t2+1+cnt,cmp);
	long long c=0,ans=0;
	for(int i=1;i<=cnt;i++){
		long long fx=find(t2[i].x),fy=find(t2[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=t2[i].z;
			c++;
			if(c==n+p-1) break;
		}
	}
	return ans;
}
void dfs(int s,int idx){
	if(s==p){
		minn=min(minn,check());
		return;
	}
	if(idx>k) return;
	b[s+1]=idx;
	dfs(s+1,idx+1);
	dfs(s,idx+1);
}
long long solve1(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(t+1,t+1+m,cmp);
	long long c=0,ans=0;
	for(int i=1;i<=m;i++){
		long long fx=find(t[i].x),fy=find(t[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=t[i].z;
			c++;
			if(c==n-1) break;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>t[i].x>>t[i].y>>t[i].z;
	}
	if(k==0){
		cout<<solve1(); 
	}
	else{
		bool flag=false;
		for(int i=1;i<=k;i++){
			cin>>v[i].n;
			if(v[i].n!=0) flag=true;
			for(int j=1;j<=n;j++){
				cin>>v[i].a[j];
			}
		}
		if(!flag){
			for(p=1;p<=k;p++){
				dfs(0,1);
			}
		}
		minn=min(minn,solve1());
		cout<<minn;
	}
	return 0;
} 
