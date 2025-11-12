#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[12]={};
long long ans=1e17;
long long min(long long a,long long b){
	return a<b?a:b;
}
struct road{
	int u,v,w;
	int id;
}a[1200000]={};
int fa[10100]={};
bool us[12]={};
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
	return;
}
bool cmp(road a,road b){
	return a.w<b.w;
}
long long q(int h){
	long long sum=0;
	for(int i=1;i<=k;i++){
		if(us[i])sum+=c[i];
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(a[i].id!=0 && us[a[i].id]==0)continue;
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			cnt++;
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
			//cout << sum << ' ' << a[i].u << ' ' << a[i].v << endl;
		}
		if(cnt==(n-1+h))break;
	}
	return sum;
}
int uuu=0;
void dfs(int kk){
	if(kk>=k){
		ans=min(ans,q(uuu));
		//cout << uuu << ' ' << q(uuu) << endl;
		return;
	}
	dfs(kk+1);
	us[kk+1]=1;
	uuu++;
	dfs(kk+1);
	us[kk+1]=0;
	uuu--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	bool ppppp=0;
	for(int i=1;i<=k;i++){
		cin >> c[i];
		if(c[i]>0)ppppp=1;
		for(int j=1;j<=n;j++){
			m++;
			cin >> a[m].w;
			if(a[m].w>0)ppppp=1;
			a[m].u=n+i;
			a[m].v=j;
			a[m].id=i;
		}
	}
	sort(a+1,a+1+m,cmp);
	if(k==0){
		cout << q(0);
		return 0;
	}
	if(ppppp==0){
		cout << 0;
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << endl;
//	}
	dfs(0);
	cout << ans;
	return 0;
}
