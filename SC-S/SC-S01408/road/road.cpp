#include<bits/stdc++.h>
using namespace std;
struct T{
	long long w,u,v;
}a[2000105];
bool cmp(T x,T y){
	return x.w<y.w;
}
long long fa[10105];
long long find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)fa[i]=i;
	int top=0;
	for(long long i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		top++;
	}
	for(long long i=1;i<=k;i++){
		fa[n+i]=n+i;
	}
	for(long long i=1;i<=k;i++){
		long long tmp;
		cin>>tmp;
		for(long long j=1;j<=n;j++){
			cin>>tmp;
			a[++top].u=i+n;
			a[top].v=j;
			a[top].w=tmp;
		}
	}
//	for(int i=1;i<=top;i++){
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
//	}
	sort(a+1,a+top+1,cmp);
//	for(int i=1;i<=top;i++){
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
//	}
	long long cnt=0;
	long long ans=0;
	for(long long i=1;i<=m+n*k;i++){
		if(find(a[i].u)!=find(a[i].v)){
			ans+=a[i].w;
			cnt++;
			fa[find(a[i].u)]=find(a[i].v);
		if(cnt==n+k-1)break;
		}
	}
	cout<<ans;
	return 0;
} 